/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:04:18 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/06 20:04:31 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_int2	findplayer(t_cubcfg *cfg)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < cfg->ln)
	{
		j = 0;
		while (cfg->lines[i][j])
		{
			c = cfg->lines[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				return ((t_int2){.x = j, .y = i});
			j++;
		}
		i++;
	}
	return ((t_int2){.x = -1, .y = -1});
}
