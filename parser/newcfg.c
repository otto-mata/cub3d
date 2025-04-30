/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubcfg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 04:35:47 by ottomata          #+#    #+#             */
/*   Updated: 2025/04/30 04:38:04 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cubcfg	*newcfg(void)
{
	t_cubcfg	*cfg;

	cfg = malloc(sizeof(*cfg));
	if (!cfg)
		return (0);
	memset(cfg, 0, sizeof(*cfg));
	return (cfg);
}
