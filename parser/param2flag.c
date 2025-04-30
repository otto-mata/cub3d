/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param2flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 05:47:22 by ottomata          #+#    #+#             */
/*   Updated: 2025/04/30 05:47:30 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	param2flag(char *l)
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
