/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   window.c                                             ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/04/08 13:33:25 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/04/08 13:33:36 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_wrapper.h>

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
