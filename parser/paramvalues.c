/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramvalues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 05:46:00 by ottomata          #+#    #+#             */
/*   Updated: 2025/04/30 05:58:04 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_rgb	a2rgb(char *s)
{
	t_rgb	rgb;

	rgb.r = atoi(s);
	s += strcspn(s, ",");
	rgb.g = atoi(s);
	s += strcspn(s, ",");
	rgb.b = atoi(s);
	return (rgb);
}

int	paramvalues(t_cubcfg *cfg)
{
	int	i;
	int	lf;

	if (!cfg)
		return (0);
	i = 0;
	while (i < cfg->ln)
	{
		lf = param2flag(cfg->lines[i]);
		if (lf == NO)
			strcpy(cfg->texpath.no, cfg->lines[i] + 3);
		else if (lf == SO)
			strcpy(cfg->texpath.so, cfg->lines[i] + 3);
		else if (lf == WE)
			strcpy(cfg->texpath.we, cfg->lines[i] + 3);
		else if (lf == EA)
			strcpy(cfg->texpath.ea, cfg->lines[i] + 3);
		else if (lf == F)
			cfg->clr.f = a2rgb(cfg->lines[i]);
		else if (lf == C)
			cfg->clr.c = a2rgb(cfg->lines[i]);
		i++;
	}
	return (1);
}
