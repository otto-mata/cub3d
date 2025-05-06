/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:24:54 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/06 19:23:14 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	floodfill(t_cubcfg *cfg, int x, int y)
{
	int	r;

	if (y >= 1 && y < cfg->ln - 1 && x >= 1 && x < strlen(cfg->lines[y]) - 1)
	{
		if (cfg->lines[y][x] == 'N')
			cfg->lines[y][x] = '0';
		if (cfg->lines[y][x] == '0')
		{
			cfg->lines[y][x] = '*';
			floodfill(cfg, x, y + 1);
			floodfill(cfg, x + 1, y);
			floodfill(cfg, x, y - 1);
			floodfill(cfg, x - 1, y);
		}
	}
}
