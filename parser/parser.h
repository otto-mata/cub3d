/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 04:32:01 by ottomata          #+#    #+#             */
/*   Updated: 2025/04/30 05:56:05 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <ctype.h>
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define MAP_MAX_SIZE 262144

typedef struct s_cub_file_cfg	t_cubcfg;
typedef struct s_color_rgb		t_rgb;

enum							e_cfg_flags
{
	NO = 1 << 0,
	SO = 1 << 1,
	WE = 1 << 2,
	EA = 1 << 3,
	F = 1 << 4,
	C = 1 << 5,
	OK = NO | SO | WE | EA | F | C,
};

struct							s_color_rgb
{
	int							r;
	int							g;
	int							b;
};

struct							s_cub_file_cfg
{
	struct						s_textures_paths
	{
		char					no[PATH_MAX];
		char					so[PATH_MAX];
		char					we[PATH_MAX];
		char					ea[PATH_MAX];
	} texpath;
	struct						s_textures
	{
		void					*no;
		void					*so;
		void					*we;
		void					*ea;
	} tex;

	struct						s_colors
	{
		t_rgb					f;
		t_rgb					c;
	} clr;
	char						map[MAP_MAX_SIZE];
	char						*lines[MAP_MAX_SIZE / 512];
	int							ln;
};

int								emptyline(char *l);
int								param2flag(char *l);
char							*gnl(int fd);
t_cubcfg						*newcfg(void);
int								parsefile(int fd, t_cubcfg *dest);
int								parampresence(t_cubcfg *cfg);
int								paramvalues(t_cubcfg *cfg);
#endif
