/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:03:46 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/02 16:16:14 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*substr(char *s, t_u32 start, t_u64 len)
{
	size_t	i;
	size_t	ssz;
	size_t	newsz;
	char	*subs;

	if (!s)
		return (0);
	ssz = strlen(s);
	if (start > ssz)
		return (strdup(""));
	newsz = ssz - start;
	if (newsz > len)
		newsz = len;
	subs = malloc((newsz + 1) * sizeof(char));
	if (!subs)
		return (0);
	memset(subs, 0, newsz + 1);
	i = 0;
	while (i < newsz)
		subs[i++] = s[start++];
	return (subs);
}
