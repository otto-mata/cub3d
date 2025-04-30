/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsefile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 04:38:48 by ottomata          #+#    #+#             */
/*   Updated: 2025/04/30 05:12:34 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	param2flag(char *l)
{
	int	f;

	f = 0;
	if (strncmp("NO", l, 2) == 0)
		f = NO;
	else if (strncmp("SO", l, 2) == 0)
		f = SO;
	else if (strncmp("WE", l, 2) == 0)
		f = WE;
	else if (strncmp("EA", l, 2) == 0)
		f = EA;
	else if (strncmp("F", l, 1) == 0)
		f = F;
	else if (strncmp("C", l, 1) == 0)
		f = C;
	if ((f == NO || f == SO || f == WE || f == EA) && !isspace(l[2]))
		f = 0;
	else if ((f == F || f == C) && !isspace(l[1]))
		f = 0;
	return (f);
}

static int	texvalid(t_cubcfg *cfg)
{
	int	i;
	int	flag;
	int	lf;

	if (!cfg)
		return (1);
	i = 0;
	flag = 0;
	while (i < cfg->ln)
	{
		lf = param2flag(cfg->lines[i++]);
		if (flag & lf)
			flag ^= lf;
		else
			flag |= lf;
	}
	return (flag == OK);
}

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
	if (!texvalid(dest))
		return (1);
	return (0);
}
