/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   engine.c                                             ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/04/06 15:43:25 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/04/06 16:20:09 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>


static int	initialize_graphics_engine(t_engine *engine)
{
	engine->graphics = mlx_init();
	if (!engine->graphics)
		return (0);
	return (1);
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

static t_image	*setup_image(t_engine *engine)
{
	t_image	*img;
	t_mlx_wrapper	*wrapper;

	wrapper = get_mlx_wrapper();
	img = malloc(sizeof(t_image));
	if (!img)
		return (0);
	img->image = new_image(engine->screen.width, engine->screen.height);
	if (wrapper->error.code)
	{
		printf("Error: %s\n", wrapper->error.info);
		free(img);
		return (0);
	}	
	img->data = mlx_get_data_addr(img->image, &img->bpp, &img->line_length,
			&img->image->byte_order);
	if (!img->data)
	{
		printf("Error: Failed to set data pointer in image structure.");
		free(img);
		return (0);
	}
	return (img);
}

int	setup_engine_screen(void)
{
	t_engine		*engine;
	t_mlx_wrapper	*wrapper;

	engine = get_engine();
	wrapper = get_mlx_wrapper();
	engine->screen.window = new_window(engine->screen.width,
			engine->screen.height);
	if (wrapper->error.code){
		printf("Error: %s\n", wrapper->error.info);
		return (1);	
	}
	engine->screen.image = setup_image(engine);
	if (!engine->screen.image)
		return (1);
	return (0);
}

