/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 04:58:07 by ottomata          #+#    #+#             */
/*   Updated: 2025/05/06 20:11:13 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(void)
{
	int			cubfd;
	t_cubcfg	*cfg;
	int			i;

	cubfd = open("./sample.cub", O_RDONLY);
	cfg = newcfg();
	printf("?parsefile: %d\n", parsefile(cubfd, cfg));
	close(cubfd);
	printf("?parampresence: %d\n", parampresence(cfg));
	printf("?paramvalues: %d\n", paramvalues(cfg));
	removeheader(cfg);
	printf("?validatemap: %d\n", validatemap(cfg));
	cfg->ppos = findplayer(cfg);
	cfg->bearing = cfg->lines[cfg->ppos.y][cfg->ppos.x];
	printf("closed? %d\n", mapenclosure(cfg));
	i = 0;
	while (i < cfg->ln)
	{
		printf("%s\n", cfg->lines[i]);
		i++;
	}
	free(cfg);
}
