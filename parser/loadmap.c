/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:06:48 by ottomata          #+#    #+#             */
/*   Updated: 2025/05/08 03:06:24 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	mapcheck(t_cubcfg *cfg)
{
	if (!parampresence(cfg))
	{
		printf("Missing parameters in map file.\n");
		return (0);
	}
	if (!paramvalues(cfg))
	{
		printf("Invalid parameter value in map file.\n");
		return (0);
	}
	removeheader(cfg);
	if (!validatemap(cfg))
	{
		printf("Invalid character in map file.\n");
		return (0);
	}
	cfg->ppos = findplayer(cfg);
	cfg->bearing = cfg->lines[cfg->ppos.y][cfg->ppos.x];
	if (!mapenclosure(cfg))
	{
		printf("Accessible map parts are not enclosed\n");
		return (0);
	}
	return (1);
}

t_cubcfg	*loadmap(const char *path)
{
	int			fd;
	t_cubcfg	*cfg;

	if (!path)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	cfg = newcfg();
	if (!parsefile(fd, cfg))
	{
		free(cfg);
		return (0);
	}
	close(fd);
	if (!mapcheck(cfg))
	{
		free(cfg); /* TODO: FREE EVERYTHING IN STRUCT */
		return (0);
	}
	return (cfg);
}
