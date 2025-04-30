/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 05:12:07 by ottomata          #+#    #+#             */
/*   Updated: 2025/04/30 05:12:08 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*gnl(int fd)
{
	static char	buffer[65536] = {0};
	ssize_t		rd_n;
	char		*ret;
	size_t		spn;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	while (1)
	{
		rd_n = read(fd, buffer, 65536);
		if (strchr(buffer, '\n') || rd_n <= 0)
			break ;
	}
	if (rd_n == 0 && !strlen(buffer))
		return (0);
	spn = strcspn(buffer, "\n");
	ret = strndup(buffer, spn + 1);
	memmove(buffer, &buffer[spn + 1], 65536 - spn + 1);
	return (ret);
}
