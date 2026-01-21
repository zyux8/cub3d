/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbarthol <pbarthol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 23:51:41 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/21 17:21:41 by pbarthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_frame(t_minimap *minimap)
{
	int	x;

	x = 0;
	while (x <= minimap->img->width)
		my_pixel_put(minimap->img, x++, 0, create_rgb(0, 0, 0));
	while (x >= 0)
		my_pixel_put(minimap->img, x--, minimap->img->width - 1, create_rgb(0,
				0, 0));
	x = 0;
	while (x <= minimap->img->height)
		my_pixel_put(minimap->img, 0, x++, create_rgb(0, 0, 0));
	while (x >= 0)
		my_pixel_put(minimap->img, minimap->img->height - 1, x--, create_rgb(0,
				0, 0));
}

int	player_close_to_door(t_data *data)
{
	int	**map;
	int	p_x;
	int	p_y;
	int	y;
	int	x;

	if (!data || !data->map || !data->map->map || !data->player)
		return (0);
	map = data->map->map;
	p_x = (int)data->player->x_pos;
	p_y = (int)data->player->y_pos;
	x = -2;
	while (++x <= 1)
	{
		y = -2;
		while (++y <= 1)
		{
			if (p_x + x >= 0 && p_x + x < data->map->map_width && p_y + y >= 0
				&& p_y + y < data->map->map_height)
				if (map[p_y + y][p_x + x] == DOOR)
					return (1);
		}
	}
	return (0);
}

void	draw_fov(t_data *data)
{
	float	angle;
	float	ray_x;
	float	ray_y;
	float	step;

	angle = data->player->facing - (data->map->actual_fov / 2);
	while (angle <= data->player->facing + (data->map->actual_fov / 2))
	{
		ray_x = data->player->x_pos;
		ray_y = data->player->y_pos;
		step = -0.02f;
		while (step < 20.0f)
		{
			ray_x = data->player->x_pos + cos(angle) * step;
			ray_y = data->player->y_pos + sin(angle) * step;
			if (data->map->map[(int)ray_y][(int)ray_x] == WALL
				|| data->map->map[(int)ray_y][(int)ray_x] == DOOR)
				break ;
			my_pixel_put(data->minimap->img, 100 + (int)
				((ray_x - data->player->x_pos) * TILE_SIZE), 100 + (int)
				((ray_y - data->player->y_pos) * TILE_SIZE), 5263440);
			step += 0.02f;
		}
		angle += 0.01f;
	}
}
