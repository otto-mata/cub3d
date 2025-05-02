/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:01:38 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/02 16:26:42 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	updateone(char *l, size_t sz)
{
	size_t	i;

	i = 0;
	while (i < sz)
	{
		if (l[i] != '\n' && isspace(l[i]))
			l[i] = '0';
		i++;
	}
}

static void	updatelines(t_cubcfg *cfg)
{
	int		l;
	char	*s;
	size_t	ls;
	size_t	i;

	l = 0;
	while (l < cfg->ln)
	{
		ls = strlen(cfg->lines[l]);
		updateone(cfg->lines[l], ls);
		if (ls < cfg->maxlen)
		{
			s = calloc(cfg->maxlen + 1, sizeof(char));
			strncat(s, cfg->lines[l], ls - 1);
			i = 0;
			while (ls + (i++) < cfg->maxlen)
				strcat(s, "0");
			s[ls + i - 2] = '\n';
			free(cfg->lines[l]);
			cfg->lines[l] = s;
		}
		l++;
	}
}

int	padmap(t_cubcfg *cfg)
{
	size_t	i;

	i = 0;
	while (i < cfg->size)
	{
		if (cfg->map[i] != '\n' && isspace(cfg->map[i]))
			cfg->map[i] = '0';
		i++;
	}
	updatelines(cfg);
	return (1);
}
