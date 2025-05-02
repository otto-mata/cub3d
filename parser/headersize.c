/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headersize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:08:02 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/02 15:07:27 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	headersize(t_cubcfg *cfg)
{
	size_t sz;
	int i;

	i = 0;
	sz = 0;
	while (i < cfg->hend - 1)
		sz += strlen(cfg->lines[i++]);
	return (sz);
}
