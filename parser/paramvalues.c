/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramvalues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 05:46:00 by ottomata          #+#    #+#             */
/*   Updated: 2025/05/06 20:10:11 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.h"
#include "parser.h"

static t_u8	a2clr(char *s, char **err)
{
	t_u32	res;
	t_i8	g;

	g = 0;
	res = 0;
	while (isspace(*s))
		s++;
	if (!isdigit(*s))
		return (*err = "invalid value, only spaces and digits allowed.", 0);
	while (*s && isdigit(*s) && !g)
	{
		res *= 10;
		g = __builtin_add_overflow(res, *s - '0', &res);
		s++;
	}
	if (g || res > 255)
		return (*err = "color must be in range [0, 255]", 0);
	*err = 0;
	return ((t_u8)res);
}

static t_rgb	a2rgb(char *s)
{
	t_rgb	rgb;
	t_u8	c;
	char	*es;

	es = 0;
	c = a2clr(s, &es);
	if (es)
		printf("%s\n", es);
	rgb.r = c;
	s += strcspn(s, ",") + 1;
	c = a2clr(s, &es);
	if (es)
		printf("%s\n", es);
	rgb.g = c;
	s += strcspn(s, ",") + 1;
	c = a2clr(s, &es);
	if (es)
		printf("%s\n", es);
	rgb.b = c;
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
			cfg->clr.f = a2rgb(cfg->lines[i] + 2);
		else if (lf == C)
			cfg->clr.c = a2rgb(cfg->lines[i] + 2);
		i++;
	}
	return (1);
}
