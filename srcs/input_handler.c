/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:42:31 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/12 19:43:01 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_destroy(t_data *data)
{
	cleanup_and_exit(data);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		data->keys->key_up = 1;
	if (keycode == KEY_DOWN || keycode == KEY_S)
		data->keys->key_do = 1;
	if (keycode == KEY_LEFT || keycode == KEY_A)
		data->keys->key_le = 1;
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		data->keys->key_ri = 1;
	if (keycode == SP)
		data->keys->space = 1;
	if (keycode == KEY_ESC)
		cleanup_and_exit(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		data->keys->key_up = 0;
	if (keycode == KEY_DOWN || keycode == KEY_S)
		data->keys->key_do = 0;
	if (keycode == KEY_LEFT || keycode == KEY_A)
		data->keys->key_le = 0;
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		data->keys->key_ri = 0;
	if (keycode == SP)
		data->keys->space = 0;
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	int	center_x;
	int	center_y;

	(void)y;
	center_x = WIN_WIDTH / 2;
	center_y = WIN_HEIGHT / 2;
	if (x == center_x)
		return (0);
	data->player->facing += (x - center_x) * MOUSE_SENSITIVITY;
	mlx_mouse_move(data->mlx, data->win, center_x, center_y);
	return (0);
}
