/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:04:16 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/18 00:41:13 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_minimap(t_data *data)
{
	if (!data || !data->minimap)
		exit(1);
	data->minimap->img = ft_calloc(1, sizeof(t_img));
	if (!data->minimap->img)
		exit(1);
	data->minimap->img->width = MINIMAP_W;
	data->minimap->img->height = MINIMAP_H;
	data->minimap->img->img = mlx_new_image(data->mlx, MINIMAP_W, MINIMAP_H);
	if (!data->minimap->img->img)
		exit(1);
	data->minimap->img->addr = mlx_get_data_addr(data->minimap->img->img,
			&data->minimap->img->bits_per_pixel, &data->minimap->img->line_len,
			&data->minimap->img->endian);
	if (!data->minimap->img->addr)
		exit(1);
	data->minimap->x_off = 0;
	data->minimap->y_off = 0;
}

void	init_data(t_data *data)
{
	if (!data)
		exit(1);
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	data->view = ft_calloc(1, sizeof(t_img));
	data->minimap = ft_calloc(1, sizeof(t_minimap));
	if (!data->view || !data->minimap)
		exit(1);
	data->view->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->view->addr = mlx_get_data_addr(data->view->img,
			&data->view->bits_per_pixel, &data->view->line_len,
			&data->view->endian);
	data->view->width = WIN_WIDTH;
	data->view->height = WIN_HEIGHT;
	init_minimap(data);
	data->keys = init_key_struct();
}

void	cleanup_and_exit(t_data *data)
{
	if (!data)
		exit(0);
	if (data->view)
	{
		if (data->view->img)
			mlx_destroy_image(data->mlx, data->view->img);
		free(data->view);
	}
	if (data->minimap)
	{
		if (data->minimap->img->img)
			mlx_destroy_image(data->mlx, data->minimap->img->img);
		free(data->minimap);
	}
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}

void	update_player_pos(t_data *data)
{
	if (data->keys->key_up)
		move_player(data, cos(data->player->facing) * MOVE_SPEED,
			sin(data->player->facing) * MOVE_SPEED);
	if (data->keys->key_do)
		move_player(data, -cos(data->player->facing) * MOVE_SPEED,
			-sin(data->player->facing) * MOVE_SPEED);
	if (data->keys->key_le)
		data->player->facing -= ROT_SPEED;
	if (data->keys->key_ri)
		data->player->facing += ROT_SPEED;
}

int	render_everything(t_data *data)
{
	update_player_pos(data);
	if (data->view && data->view->addr)
		ft_bzero(data->view->addr, (size_t)data->view->line_len
			* (size_t)data->view->height);
	if (data->minimap && data->minimap->img->addr)
		ft_bzero(data->minimap->img->addr, (size_t)data->minimap->img->line_len
			* (size_t)data->minimap->img->height);
	// raycasting();
	draw_minimap(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->view->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->minimap->img->img, 20, 20);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2 || !ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
	{
		printf("Usage: './cub3d' <map.cub>\n");
		return (1);
	}
	init_data(&data);
	if (check_map(av[1], &data))
		return (cleanup_and_exit(&data), 0);
	init_minimap(&data);
	for (int x = 0; x < 250; x++)
		my_pixel_put(data.view, 250, x, create_rgb(200, 40, 20));
	for (int y = 0; y < 250; y++)
		my_pixel_put(data.view, y, 250, create_rgb(200, 40, 20));
	mlx_loop_hook(data.mlx, render_everything, &data);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.win, 17, 0, handle_destroy, &data);
	mlx_loop(data.mlx);
	return (0);
}
