/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:23:41 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/19 16:40:14 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_minimap(t_data *data)
{
	if (!data || !data->minimap)
		exit(1);
	data->minimap->img = ft_calloc(1, sizeof(t_img));
	if (!data->minimap->img)
		exit(1);
	data->minimap->img->width = MINIMAP_W;
	data->minimap->img->height = MINIMAP_H;
	data->minimap->img->img = mlx_new_image(data->mlx, MINIMAP_W, MINIMAP_H);
	if (!data->minimap->img->img)
		exit(1);
	data->minimap->img->addr = mlx_get_data_addr(data->minimap->img->img,
			&data->minimap->img->bits_per_pixel, &data->minimap->img->line_len,
			&data->minimap->img->endian);
	if (!data->minimap->img->addr)
		exit(1);
	data->minimap->x_off = 0;
	data->minimap->y_off = 0;
}

void	draw_square(t_data *data, int x_pos, int y_pos, int block)
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
				my_pixel_put(data->minimap->img, x_pos + x, y_pos + y,
					create_rgb(200, 200, 200));
			else if (block == DOOR && !player_close_to_door(data))
				my_pixel_put(data->minimap->img, x_pos + x, y_pos + y,
					create_rgb(200, 200, 200));
			else if (block != NONE)
				my_pixel_put(data->minimap->img, x_pos + x, y_pos + y,
					create_rgb(40, 40, 40));
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
			my_pixel_put(data->minimap->img, px + x, py + y, create_rgb(250, 50,
					50));
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
	while (x < 50)
	{
		my_pixel_put(data->minimap->img, center_x
			+ (int)(cos(data->player->facing) * x), center_x
			+ (int)(sin(data->player->facing) * x), create_rgb(255, 220, 80));
		x++;
	}
	draw_player_dot(data, center_x, center_y);
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
				draw_square(data, draw_x, draw_y, data->map->map[y][x]);
			x++;
		}
		y++;
	}
	draw_frame(data->minimap);
}
