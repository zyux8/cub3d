/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:04:16 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/11 20:02:42 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (!data)
		exit(1); // exitfunction maybe
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_len, &data->endian);
}

void	cleanup_and_exit(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	(void)av;
	init_data(&data);
	if (!check_map(av[1], &data))
		return (0);
	for (int x = 100; x < 300; x++)
		my_pixel_put(&data, x, 400, data.map->ceiling_color);
	for (int y = 100; y < 300; y++)
		my_pixel_put(&data, 200, y, data.map->floor_color);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
	mlx_hook(data.win, 17, 0, handle_destroy, &data);
	mlx_loop(data.mlx);
	return (0);
}
