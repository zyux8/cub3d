/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:34:48 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/22 22:16:58 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (!img || !img->addr)
		return ;
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

t_keys	*init_key_struct(void)
{
	t_keys	*key;

	key = malloc(sizeof(t_keys));
	if (!key)
		return (NULL);
	key->key_up = 0;
	key->key_do = 0;
	key->key_ri = 0;
	key->key_le = 0;
	key->key_w = 0;
	key->key_a = 0;
	key->key_s = 0;
	key->key_d = 0;
	key->key_sp = 0;
	return (key);
}

void	update_player_pos(t_data *data)
{
	if (data->keys->key_sp)
		update_player_movement(data, MOVE_SPEED + 0.1);
	else if (!data->keys->key_sp)
		update_player_movement(data, MOVE_SPEED);
	if (data->keys->key_d)
		move_player(data, cos(data->player->facing + (PI / 2)) * (MOVE_SPEED
				/ 1.8), sin(data->player->facing + (PI / 2)) * (MOVE_SPEED
				/ 1.8));
	if (data->keys->key_a)
		move_player(data, -cos(data->player->facing + (PI / 2)) * (MOVE_SPEED
				/ 1.8), -sin(data->player->facing + (PI / 2)) * (MOVE_SPEED
				/ 1.8));
	if (data->keys->key_le)
		data->player->facing -= ROT_SPEED;
	if (data->keys->key_ri)
		data->player->facing += ROT_SPEED;
}

void	move_player(t_data *data, double move_x, double move_y)
{
	if ((int)(data->player->x_pos + move_x) > 0 && (int)(data->player->x_pos
			+ move_x) < data->map->map_width)
		data->player->x_pos += move_x;
	if ((int)(data->player->y_pos + move_y) > 0 && (int)(data->player->y_pos + move_y) < data->map->map_height)
		data->player->y_pos += move_y;
}
