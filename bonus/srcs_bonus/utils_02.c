/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:44:35 by pbarthol          #+#    #+#             */
/*   Updated: 2026/01/26 14:20:00 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_fps_count	*init_fps_count(void)
{
	t_fps_count	*fps_count;

	fps_count = malloc(sizeof(t_fps_count));
	if (!fps_count)
		return (NULL);
	fps_count->fps = 0;
	fps_count->last_frame = 0;
	return (fps_count);
}

void	c3_fps_count(t_data *data)
{
	struct timeval	tv;
	double			current_frame;
	char			*fps_str;

	gettimeofday(&tv, NULL);
	current_frame = (tv.tv_usec / 1000) + (tv.tv_sec * 1000);
	data->fps_count->fps = 1000 / (current_frame - data->fps_count->last_frame);
	data->fps_count->last_frame = current_frame;
	fps_str = ft_itoa((int)data->fps_count->fps);
	mlx_string_put(data->mlx, data->win, 240, 30, 0xFFFFFF, fps_str);
	free(fps_str);
}

void	update_player_movement(t_data *data, float speed)
{
	if (data->keys->key_up || data->keys->key_w)
		move_player(data, cos(data->player->facing) * speed,
			sin(data->player->facing) * speed);
	if (data->keys->key_do || data->keys->key_s)
		move_player(data, -cos(data->player->facing) * speed,
			-sin(data->player->facing) * speed);
}
