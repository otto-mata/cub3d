/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeheader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:16:52 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/02 14:48:35 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	removeheader(t_cubcfg *cfg)
{
	const size_t	sz = headersize(cfg);

	memmove(cfg->map, cfg->map + sz, MAP_MAX_SIZE - sz);
	cfg->ln -= cfg->hend - 1;
	memmove(cfg->lines, &cfg->lines[cfg->hend - 1], (cfg->ln) * sizeof(void *));
	cfg->size = strlen(cfg->map);
}
