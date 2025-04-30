/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 04:58:07 by ottomata          #+#    #+#             */
/*   Updated: 2025/04/30 06:07:09 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(void)
{
	int			cubfd;
	t_cubcfg	*cfg;

	cubfd = open("./sample.cub", O_RDONLY);
	cfg = newcfg();
	printf("?parsefile: %d\n", parsefile(cubfd, cfg));
	close(cubfd);
	printf("?parampresence: %d\n", parampresence(cfg));
	printf("?paramvalues: %d\n", paramvalues(cfg));
	printf("NO>%s\nSO>%s\nWE>%s\nEA>%s\n", cfg->texpath.no, cfg->texpath.so,
		cfg->texpath.we, cfg->texpath.ea);
	printf("F>(%d, %d, %d)\nC>(%d, %d, %d)\n", cfg->clr.f.r, cfg->clr.f.g,
		cfg->clr.f.b, cfg->clr.c.r, cfg->clr.c.g, cfg->clr.c.b);
	free(cfg);
}
