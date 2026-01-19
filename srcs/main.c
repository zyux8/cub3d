/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbarthol <pbarthol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:04:16 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/19 21:05:22 by pbarthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_view(t_data *data)
{
	data->view = ft_calloc(1, sizeof(t_img));
	if (!data->view)
		return (0);
	data->view->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->view->addr = mlx_get_data_addr(data->view->img,
			&data->view->bits_per_pixel, &data->view->line_len,
			&data->view->endian);
	data->view->width = WIN_WIDTH;
	data->view->height = WIN_HEIGHT;
	return (1);
}

void	init_data(t_data *data)
{
	if (!data)
		exit(1);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	if (!init_view(data) || !data->mlx)
		exit(1);
	data->minimap = ft_calloc(1, sizeof(t_minimap));
	if (!data->minimap)
		exit(1);
	init_minimap(data);
	data->player = NULL;
	data->keys = init_key_struct();
	data->cigar = init_cigar(data);
	mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	mlx_mouse_hide(data->mlx, data->win);
}

int	render_everything(t_data *data)
{
	update_player_pos(data);
	c3_rycst_main(data);
	draw_minimap(data);
	load_cigar(data);
	mlx_put_image_to_window(data->mlx, data->win, data->view->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->minimap->img->img, 20,
		20);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (!check_map(ac, av, &data))
		return (cleanup_and_exit(&data), 1);
	mlx_loop_hook(data.mlx, render_everything, &data);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.win, 6, 1L << 6, mouse_move, &data);
	mlx_hook(data.win, 17, 0, handle_destroy, &data);
	mlx_loop(data.mlx);
	return (cleanup_and_exit(&data), 0);
}
