/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:42:31 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/18 01:17:28 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_data *data, double move_x, double move_y)
{
	if (data->map->map[(int)(data->player->y_pos)][(int)(data->player->x_pos
			+ move_x)] != WALL)
		data->player->x_pos += move_x;
	if (data->map->map[(int)(data->player->y_pos
			+ move_y)][(int)(data->player->x_pos)] != WALL)
		data->player->y_pos += move_y;
}

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
	return (0);
}

/*
void	update_player_pos(t_data *data)
{
	if (data->key_w)
		move_player(data, cos(data->player.angle) * MOVE_SPEED,
			sin(data->player.angle) * MOVE_SPEED);
	if (data->key_s)
		move_player(data, -cos(data->player.angle) * MOVE_SPEED,
			-sin(data->player.angle) * MOVE_SPEED);
	if (data->key_a)
		move_player(data, sin(data->player.angle) * MOVE_SPEED,
			-cos(data->player.angle) * MOVE_SPEED);
	if (data->key_d)
		move_player(data, -sin(data->player.angle) * MOVE_SPEED,
			cos(data->player.angle) * MOVE_SPEED);
	if (data->key_left)
		data->player.angle -= ROT_SPEED;
	if (data->key_right)
		data->player.angle += ROT_SPEED;
}

mlx_hook(data.win, 2, 1L << 0, key_press, &data);
mlx_hook(data.win, 3, 1L << 1, key_release, &data);
*/