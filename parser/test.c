/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 04:58:07 by ottomata          #+#    #+#             */
/*   Updated: 2025/04/30 05:12:34 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(void)
{
	int			cubfd;
	t_cubcfg	*cfg;

	cubfd = open("./sample.cub", O_RDONLY);
	cfg = newcfg();
	printf("?: %d\n", parsefile(cubfd, cfg));
}
