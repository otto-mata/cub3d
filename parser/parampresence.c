/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parampresence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 05:16:51 by ottomata          #+#    #+#             */
/*   Updated: 2025/04/30 05:43:54 by ottomata         ###   ########.fr       */
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
	else
		f = (!emptyline(l)) * (1 << 20);
	if ((f == NO || f == SO || f == WE || f == EA) && !isspace(l[2]))
		f = 0;
	else if ((f == F || f == C) && !isspace(l[1]))
		f = 0;
	return (f);
}

/**
 * @brief Checks for the presence of all params in a CUB file
 * @param cfg config struct
 * @return 1 if OK, 0 if KO
 *
 * Impl. details:
 *
 * 	=> if (lf && lf != (1 << fn))
 * 		This checks wether the NO, SO, WE, EA, F, C order is respected.
 *
 * 	=> if (flag & lf)
 * 		This checks for possible duplicates in the parameters.
 *
 * 	=> flag |= lf
 * 		This sets the bit corresponding to the param to 1.
 */
int	parampresence(t_cubcfg *cfg)
{
	int	i;
	int	fn;
	int	flag;
	int	lf;

	if (!cfg)
		return (1);
	i = 0;
	flag = 0;
	fn = 0;
	while (i < cfg->ln)
	{
		lf = param2flag(cfg->lines[i++]);
		if (lf == (1 << 20))
			return (flag == OK);
		if (lf && lf != (1 << fn))
			return (0);
		if (lf)
			fn++;
		if (flag & lf)
			return (0);
		else
			flag |= lf;
	}
	return (flag == OK);
}
