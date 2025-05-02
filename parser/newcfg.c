/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newcfg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 04:35:47 by ottomata          #+#    #+#             */
/*   Updated: 2025/05/02 14:05:01 by tblochet         ###   ########.fr       */
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
