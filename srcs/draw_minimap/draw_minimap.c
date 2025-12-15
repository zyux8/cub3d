/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:23:41 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/15 03:04:43 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_data *data, int x_pos, int y_pos, int col)
{
	int	x;
	int	y;

	x = 0;
	while (x <= MINIMAP_SIZE)
	{
		y = 0;
		while (y <= MINIMAP_SIZE)
		{
			my_pixel_put(data, x_pos + x, y_pos + y, col);
			y++;
		}
		x++;
	}
}

int	draw_minimap(t_data *data)
{
	int	x;
	int	y;
	int	**map_temp;

	y = 0;
	map_temp = data->map->map;
	while (y < data->map->map_height)
	{
		x = 0;
		while (x < data->map->map_width)
		{
			if (map_temp[y][x] == WALL)
				draw_square(data, x * MINIMAP_SIZE, y * MINIMAP_SIZE,
					create_rgb(180, 10, 30));
			else if (map_temp[y][x] == GROUND)
				draw_square(data, x * MINIMAP_SIZE, y * MINIMAP_SIZE,
					create_rgb(10, 180, 30));
			else if (map_temp[y][x] != NONE)
				draw_square(data, x * MINIMAP_SIZE, y * MINIMAP_SIZE,
					create_rgb(10, 180, 30));
			x++;
		}
		y++;
	}
	return (0);
}
