/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:24:54 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/05 14:03:44 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	floodfill(t_cubcfg *cfg, int x, int y)
{
	if (cfg->lines[y][x] == '\0' || isspace(cfg->lines[y][x]))
		return (0);
	if (cfg->lines[y][x] == '1')
		return (1);
	return (floodfill(cfg, x, y + 1) && floodfill(cfg, x + 1, y)
		&& floodfill(cfg, x, y - 1) && floodfill(cfg, x - 1, y));
}
