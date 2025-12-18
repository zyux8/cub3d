/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:42:31 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/18 15:51:45 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
