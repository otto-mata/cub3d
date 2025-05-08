/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 04:58:07 by ottomata          #+#    #+#             */
/*   Updated: 2025/05/08 01:40:20 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(int argc, char **argv)
{
	t_cubcfg	*cfg;
	int			i;

	if (argc < 2)
	{
		printf("Missing map file\n");
		return (1);
	}
	cfg = loadmap(argv[1]);
	i = 0;
	while (cfg && i < cfg->ln)
	{
		printf("%s\n", cfg->lines[i]);
		i++;
	}
	free(cfg);
}
