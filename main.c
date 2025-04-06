/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/04/06 15:19:25 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/04/06 16:19:22 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>


int	main(void)
{
	t_engine	*engine;

	engine = get_engine();
	if (!engine)
		return (1);
	if (setup_engine_screen())
	{
		return (1);
	}
}
