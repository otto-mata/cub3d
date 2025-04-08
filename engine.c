/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   engine.c                                             ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/04/06 15:43:25 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/04/08 15:11:44 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>

static int	initialize_graphics_engine(t_engine *engine)
{
	t_mlx_wrapper	*wrapper;

	wrapper = get_mlx_wrapper();
	if (!wrapper || !wrapper->mlx)
		return (0);
	engine->graphics = wrapper->mlx;
	return (1);
}

static void	teardown(void)
{
	t_engine		*engine;
	t_mlx_wrapper	*wrapper;

	engine = get_engine();
	wrapper = get_mlx_wrapper();
	mlx_loop_end(wrapper->mlx);
	mlx_destroy_image(wrapper->mlx, engine->screen.image->image);
	free(engine->screen.image);
	mlx_destroy_window(wrapper->mlx, engine->screen.window);
	mlx_destroy_display(wrapper->mlx);
	free(wrapper->mlx);
	exit(0);
}

t_engine	*get_engine(void)
{
	static t_engine	engine = {0};
	static char		_init = 0;

	if (!_init)
	{
		_init = 1;
		engine.screen.width = 640;
		engine.screen.half_width = (float)engine.screen.width / 2;
		engine.screen.height = 480;
		engine.screen.half_height = (float)engine.screen.height / 2;
		engine.render.delay = 30;
		engine.raycasting.precision = 64.0f;
		engine.raycasting.inc_angle = engine.player.fov / engine.screen.width;
		engine.player.fov = 60.0f;
		engine.player.half_fov = engine.player.fov / 2;
		engine.player.x = 2;
		engine.player.y = 2;
		engine.player.angle = 90.0f;
		if (initialize_graphics_engine(&engine) == 0)
			return (0);
	}
	return (&engine);
}

int	setup_engine_screen(void)
{
	t_engine		*engine;
	t_mlx_wrapper	*wrapper;

	engine = get_engine();
	wrapper = get_mlx_wrapper();
	engine->screen.window = new_window(engine->screen.width,
			engine->screen.height);
	if (wrapper->error.code)
	{
		printf("Error: %s\n", wrapper->error.info);
		return (1);
	}
	engine->screen.image = setup_image(engine->screen.width,
			engine->screen.height);
	if (!engine->screen.image)
		return (1);
	mlx_hook(engine->screen.window, DestroyNotify, ButtonPressMask,
		(int (*)()) & teardown, wrapper->mlx);
	return (0);
}
