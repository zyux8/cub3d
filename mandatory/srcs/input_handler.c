/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:42:31 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/22 22:14:59 by ohaker           ###   ########.fr       */
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
	if (keycode == KEY_UP)
		data->keys->key_up = 1;
	if (keycode == KEY_DOWN)
		data->keys->key_do = 1;
	if (keycode == KEY_LEFT)
		data->keys->key_le = 1;
	if (keycode == KEY_RIGHT)
		data->keys->key_ri = 1;
	if (keycode == KEY_W)
		data->keys->key_w = 1;
	if (keycode == KEY_A)
		data->keys->key_a = 1;
	if (keycode == KEY_S)
		data->keys->key_s = 1;
	if (keycode == KEY_D)
		data->keys->key_d = 1;
	if (keycode == KEY_SP)
		data->keys->key_sp = 1;
	if (keycode == KEY_ESC)
		cleanup_and_exit(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_UP)
		data->keys->key_up = 0;
	if (keycode == KEY_DOWN)
		data->keys->key_do = 0;
	if (keycode == KEY_LEFT)
		data->keys->key_le = 0;
	if (keycode == KEY_RIGHT)
		data->keys->key_ri = 0;
	if (keycode == KEY_W)
		data->keys->key_w = 0;
	if (keycode == KEY_A)
		data->keys->key_a = 0;
	if (keycode == KEY_S)
		data->keys->key_s = 0;
	if (keycode == KEY_D)
		data->keys->key_d = 0;
	if (keycode == KEY_SP)
		data->keys->key_sp = 0;
	return (0);
}
