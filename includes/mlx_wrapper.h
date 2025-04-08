/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   mlx_wrapper.h                                        ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/04/06 15:40:14 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/04/08 13:48:17 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WRAPPER_H
# define MLX_WRAPPER_H
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/extensions/XShm.h>
# define MAX_EVENT 36
# define WIN_TITLE "Cub3D"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_image			t_image;
typedef struct s_mlx_event_list	t_mlx_event_list;
typedef struct s_mlx_win_list	t_mlx_win_list;
typedef struct s_mlx			t_mlx;
typedef struct s_wrapper_error	t_wrapper_error;
typedef struct s_mlx_wrapper	t_mlx_wrapper;

struct							s_image
{
	XImage						*image;
	Pixmap						pix;
	GC							gc;
	int							bpp;
	int							line_length;
	int							width;
	int							height;
	int							type;
	int							format;
	char						*data;
	XShmSegmentInfo				shm;
};

struct							s_mlx_event_list
{
	int							mask;
	int							(*hook)();
	void						*param;
};

struct							s_mlx_win_list
{
	Window						window;
	GC							gc;
	struct s_win_list			*next;
	int							(*mouse_hook)();
	int							(*key_hook)();
	int							(*expose_hook)();
	void						*mouse_param;
	void						*key_param;
	void						*expose_param;
	t_mlx_event_list			hooks[MAX_EVENT];
};

struct							s_wrapper_error
{
	int							code;
	char						*info;
};

struct							s_mlx
{
	Display						*display;
	Window						root;
	int							screen;
	int							depth;
	Visual						*visual;
	Colormap					cmap;
	int							private_cmap;
	t_mlx_win_list				*win_list;
	int							(*loop_hook)();
	void						*loop_param;
	int							use_xshm;
	int							pshm_format;
	int							do_flush;
	int							decrgb[6];
	Atom						wm_delete_window;
	Atom						wm_protocols;
	int							end_loop;
};

struct							s_mlx_wrapper
{
	t_mlx						*mlx;
	t_wrapper_error				error;
};

t_mlx_wrapper					*get_mlx_wrapper(void);
t_mlx_win_list					*new_window(int width, int height);
t_image							*setup_image(int width, int height);
int								display(void);
#endif
