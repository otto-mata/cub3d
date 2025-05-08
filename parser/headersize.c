/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headersize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:08:02 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/08 02:10:23 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	headersize(t_cubcfg *cfg)
{
	size_t	sz;
	int		i;

	i = 0;
	sz = 0;
	while (i < cfg->mapstart)
		sz += strlen(cfg->lines[i++]);
	return (sz + cfg->ln);
}
