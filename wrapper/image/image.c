/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   image.c                                              ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/04/08 13:33:40 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/04/08 13:46:48 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_wrapper.h>

static XImage *new_image(int width, int height)
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

t_image	*setup_image(int width, int height)
{
	t_image	*img;
	t_mlx_wrapper	*wrapper;

	wrapper = get_mlx_wrapper();
	img = malloc(sizeof(t_image));
	if (!img)
		return (0);
	img->image = new_image(width, height);
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
