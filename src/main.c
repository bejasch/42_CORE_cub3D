/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:31:48 by bschneid          #+#    #+#             */
/*   Updated: 2024/11/01 18:14:15 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	main(int ac, char **av)
{
	t_data		data;

	check_argument(ac, av);
	if (!init_game(&data, av))
	{
		mlx_delete_image(data.mlx, data.image);
		mlx_terminate(data.mlx);
		ft_error_general(&data, "Couldn't init the game");
	}
	mlx_image_to_window(data.mlx, data.image, 0, 0);
	mlx_cursor_hook(data.mlx, &mouse_callback, &data);
	mlx_key_hook(data.mlx, &key_press, &data);
	mlx_loop_hook(data.mlx, &get_new_frame, &data);
	if (BONUS)
	{
		draw_minimap(&data);
		mlx_loop_hook(data.mlx, &animate, &data);
	}
	mlx_loop(data.mlx);
	clean_up(&data);
	return (EXIT_SUCCESS);
}
