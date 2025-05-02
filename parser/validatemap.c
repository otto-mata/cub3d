/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:38:07 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/02 15:05:15 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	countchars(t_cubcfg *cfg)
{
	size_t	i;

	i = 0;
	while (i < cfg->size)
	{
		cfg->chrn[cfg->map[i]]++;
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
		if (!strchr("10NSEW", i))
			if (cfg->chrn[i])
				return (0);
		i++;
	}
	return (1);
}
