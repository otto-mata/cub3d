/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsefile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 04:38:48 by ottomata          #+#    #+#             */
/*   Updated: 2025/05/06 19:17:20 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parsefile(int fd, t_cubcfg *cfg)
{
	char	*l;
	int		ln;
	size_t	llen;

	if (!cfg || fd < 0)
		return (0);
	ln = 0;
	while (1)
	{
		l = gnl(fd);
		if (!l)
			break ;
		strcat(cfg->map, l);
		l[strcspn(l, "\n")] = 0;
		cfg->lines[ln++] = l;
		llen = strlen(l);
		if (llen > cfg->maxlen)
			cfg->maxlen = llen;
	}
	cfg->ln = ln;
	return (1);
}
