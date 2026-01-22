/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:44:35 by pbarthol          #+#    #+#             */
/*   Updated: 2026/01/22 22:17:06 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player_movement(t_data *data, float speed)
{
	if (data->keys->key_up || data->keys->key_w)
		move_player(data, cos(data->player->facing) * speed,
			sin(data->player->facing) * speed);
	if (data->keys->key_do || data->keys->key_s)
		move_player(data, -cos(data->player->facing) * speed,
			-sin(data->player->facing) * speed);
}

int	get_pixel_color(t_img *img, int x, int y)
{
	char	*dst;

	if (!img || !img->addr)
		return (0);
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
