/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:23:41 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/18 01:20:17 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_img *minimap, int x_pos, int y_pos, int block)
{
	int	x;
	int	y;

	x = 0;
	while (x <= TILE_SIZE)
	{
		y = 0;
		while (y <= TILE_SIZE)
		{
			if (block == WALL)
				put_minimap_pixel(minimap, x_pos + x, y_pos + y, create_rgb(180,
						30, 30));
			else if (block != NONE)
				put_minimap_pixel(minimap, x_pos + x, y_pos + y, create_rgb(45,
						120, 20));
			y++;
		}
		x++;
	}
}

void	draw_player_dot(t_data *data, int px, int py)
{
	int	x;
	int	y;

	x = -4;
	while (x <= 4)
	{
		y = -4;
		while (y <= 4)
		{
			put_minimap_pixel(data->minimap->img, px + x, py + y, 0xFFFF00);
			y++;
		}
		x++;
	}
}

void	draw_player(t_data *data)
{
	int	center_x;
	int	center_y;
	int	x;

	x = 0;
	center_x = 100;
	center_y = 100;
	draw_player_dot(data, center_x, center_y);
	while (x < 50)
	{
		put_minimap_pixel(data->minimap->img, center_x
			+ (int)(cos(data->player->facing) * x), center_x
			+ (int)(sin(data->player->facing) * x), 0x0000FF);
		x++;
	}
}

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;
	int	draw_x;
	int	draw_y;

	y = 0;
	data->minimap->x_off = (data->player->x_pos * TILE_SIZE) - (MINIMAP_W / 2);
	data->minimap->y_off = (data->player->y_pos * TILE_SIZE) - (MINIMAP_H / 2);
	while (y < data->map->map_height)
	{
		x = 0;
		while (x < data->map->map_width)
		{
			draw_x = (x * TILE_SIZE) - (int)data->minimap->x_off;
			draw_y = (y * TILE_SIZE) - (int)data->minimap->y_off;
			if (draw_x > -TILE_SIZE && draw_x < 200 && draw_y > -TILE_SIZE
				&& draw_y < 200)
				draw_square(data->minimap->img, draw_x, draw_y,
					data->map->map[y][x]);
			x++;
		}
		y++;
	}
}
