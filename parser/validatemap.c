/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:38:07 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/08 02:13:14 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	countchars(t_cubcfg *cfg)
{
	size_t	i;
	size_t	j;
	i = 0;
	while (i < (size_t)cfg->ln)
	{
		j = 0;
		while (cfg->lines[i][j])
		{
			cfg->chrn[(int)cfg->lines[i][j]]++;
			j++;
		}
		i++;
	}
}

static int	validateplayer(t_cubcfg *cfg)
{
	return (cfg->chrn['N'] + cfg->chrn['S'] + cfg->chrn['E']
		+ cfg->chrn['W'] == 1);
}

int	validatemap(t_cubcfg *cfg)
{
	int	i;

	countchars(cfg);
	if (!validateplayer(cfg))
		return (0);
	i = 33;
	while (i < 128)
	{
		if (cfg->chrn[i] && !strchr("10NSEW", i))
			return (0);
		i++;
	}
	return (1);
}
