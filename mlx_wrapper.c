/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   mlx_wrapper.c                                        ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/04/06 15:53:18 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/04/06 16:19:57 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_wrapper.h>
t_mlx_wrapper	*get_mlx_wrapper(void)
{
	static t_mlx_wrapper	wrapper = {0};
	static int				_init = 0;
	
	if (!_init)
	{
		_init = 1;
		wrapper.mlx = mlx_init();
		if (!wrapper.mlx)
			return (0);
	}
	return (&wrapper);
}

t_mlx_win_list	*new_window(int width, int height)
{
	t_mlx_win_list	*win;
	t_mlx_wrapper	*wrp;

	wrp = get_mlx_wrapper();
	if (!wrp)
		return (0);
	win = mlx_new_window(wrp->mlx, width, height, WIN_TITLE);
	if (!win)
	{
		wrp->error.code = 1;
		wrp->error.info = "Failed to create a new window.";
	}
	return (win);
}

XImage *new_image(int width, int height)
{
	XImage	*image;
	t_mlx_wrapper	*wrp;

	wrp = get_mlx_wrapper();
	if (!wrp)
		return (0);
	image = mlx_new_image(wrp->mlx, width, height);
	if (!image)
	{
		wrp->error.code = 2;
		wrp->error.info = "Failed to create a new image.";
	}
	return (image);
}
