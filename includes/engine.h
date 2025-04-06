/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   engine.h                                             ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/04/06 15:42:09 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/04/06 16:15:46 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# include "common.h"
# include "mlx_wrapper.h"

typedef struct s_screen		t_screen;
typedef struct s_render		t_render;
typedef struct s_raycasting	t_raycasting;
typedef struct s_player		t_player;
typedef struct s_tex_map	t_tex_map;
typedef struct s_map		t_map;
typedef struct s_error		t_error;
typedef struct s_engine		t_engine;

struct						s_screen
{
	short					width;
	short					height;
	float					half_width;
	float					half_height;
	t_mlx_win_list			*window;
	t_image					*image;
};

struct						s_render
{
	char					delay;
};

struct						s_raycasting
{
	float					inc_angle;
	short					precision;
};

struct						s_player
{
	float					fov;
	float					half_fov;
	float					x;
	float					y;
	float					angle;
};

struct						s_tex_map
{
	int						value;
};

struct						s_map
{
	short					width;
	short					height;
	t_tex_map				textures;
	char					**values;
};

struct						s_error
{
	int						code;
	char					*info;
};

struct						s_engine
{
	t_screen				screen;
	t_render				render;
	t_raycasting			raycasting;
	t_player				player;
	t_map					map;
	t_error					error;
	t_mlx					*graphics;
};

t_engine					*get_engine(void);
int							setup_engine_screen(void);

#endif
