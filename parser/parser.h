/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 04:32:01 by ottomata          #+#    #+#             */
/*   Updated: 2025/05/08 02:59:18 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../includes/types.h"
# include "../includes/mlx.h"
# include <ctype.h>
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define MAP_MAX_SIZE 262144
# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

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
	size_t						size;
	size_t						maxlen;
	int							chrn[128];
	char						*lines[MAP_MAX_SIZE / 512];
	int							ln;
	int							mapstart;
	t_int2						ppos;
	char						bearing;
};

int								mapenclosure(t_cubcfg *cfg);
t_int2							findplayer(t_cubcfg *cfg);
char							*substr(char *s, t_u32 start, t_u64 len);
int								validatemap(t_cubcfg *cfg);
int								padmap(t_cubcfg *cfg);
void							removeheader(t_cubcfg *cfg);
size_t							headersize(t_cubcfg *cfg);
int								emptyline(char *l);
int								param2flag(char *l);
char							*gnl(int fd);
t_cubcfg						*newcfg(void);
int								parsefile(int fd, t_cubcfg *dest);
int								parampresence(t_cubcfg *cfg);
int								paramvalues(t_cubcfg *cfg);
void							floodfill(t_cubcfg *cfg, int x, int y);
t_cubcfg						*loadmap(const char *path);
#endif
