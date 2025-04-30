/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsefile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 04:38:48 by ottomata          #+#    #+#             */
/*   Updated: 2025/04/30 05:16:14 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parsefile(int fd, t_cubcfg *dest)
{
	char	*l;
	int		ln;

	if (!dest || fd < 0)
		return (1);
	ln = 0;
	while (1)
	{
		l = gnl(fd);
		if (!l)
			break ;
		strcat(dest->map, l);
		dest->lines[ln++] = l;
	}
	dest->ln = ln;
	return (0);
}
