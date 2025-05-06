/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapenclosure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:36:45 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/06 20:05:04 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	checksurroundings(t_cubcfg *cfg, int x, int y)
{
	if (y == 0 || y >= cfg->ln - 1)
		return (0);
	if (x == 0 || x >= (int)strlen(cfg->lines[y]) - 1)
		return (0);
	if (cfg->lines[y][x - 1] != '1' && cfg->lines[y][x - 1] != '*')
		return (0);
	if (cfg->lines[y][x + 1] != '1' && cfg->lines[y][x + 1] != '*')
		return (0);
	if (cfg->lines[y - 1][x] != '1' && cfg->lines[y - 1][x] != '*')
		return (0);
	if (cfg->lines[y + 1][x] != '1' && cfg->lines[y + 1][x] != '*')
		return (0);
	return (1);
}

static void	revert(t_cubcfg *cfg)
{
	int		i;
	char	*p;
	int		j;

	i = 0;
	while (i < cfg->ln)
	{
		p = strchr(cfg->lines[i], '*');
		if (p)
		{
			j = (int)(p - cfg->lines[i]);
			while (cfg->lines[i][j])
			{
				if (cfg->lines[i][j] == '*')
					cfg->lines[i][j] = '0';
				j++;
			}
		}
		i++;
	}
	cfg->lines[cfg->ppos.y][cfg->ppos.x] = cfg->bearing;
}

int	mapenclosure(t_cubcfg *cfg)
{
	int		i;
	int		j;
	char	*p;

	floodfill(cfg, cfg->ppos.x, cfg->ppos.y);
	i = 0;
	while (i < cfg->ln)
	{
		p = strchr(cfg->lines[i], '*');
		if (p)
		{
			j = (int)(p - cfg->lines[i]);
			while (cfg->lines[i][j])
			{
				if (cfg->lines[i][j] == '*' && !checksurroundings(cfg, j, i))
					return (0);
				j++;
			}
		}
		i++;
	}
	revert(cfg);
	return (1);
}
