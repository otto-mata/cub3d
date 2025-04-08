/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   wrapper.c                                            ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/04/08 13:32:25 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/04/08 15:56:29 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
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

int	display(void)
{
	t_mlx_wrapper *wrapper;

	wrapper = get_mlx_wrapper();
	return (mlx_loop(wrapper->mlx));
}

