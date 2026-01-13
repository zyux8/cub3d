/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbarthol <pbarthol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:42:20 by pbarthol          #+#    #+#             */
/*   Updated: 2026/01/13 19:23:35 by pbarthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_data *data, int pixel_col, float dist)
{
	int	i;
	int	line_height;
	int	start;

	if (dist < 1)
		line_height = WIN_HEIGHT;
	else if (dist < 5)
		line_height = WIN_HEIGHT / dist;
	else
		line_height = (WIN_HEIGHT / 2) / dist;
	start = (WIN_HEIGHT / 2) - (line_height / 2);
	i = 0;
	while (i < start)
	{
		if ((pixel_col > 20 && pixel_col < 20 + MINIMAP_W) && (i > 20 && i < 20 + MINIMAP_H))
		{
			i++;
			continue ;
		}
		mlx_pixel_put(data->mlx, data->win, pixel_col, i, data->map->ceiling_color);
		i++;
	}
	while (i < line_height)
	{
		if ((pixel_col > 20 && pixel_col < 20 + MINIMAP_W) && (i > 20 && i < 20 + MINIMAP_H))
		{
			i++;
			continue ;
		}
		mlx_pixel_put(data->mlx, data->win, pixel_col, i, 0xFFFFFF / dist);
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		if ((pixel_col > 20 && pixel_col < 20 + MINIMAP_W) && (i > 20 && i < 20 + MINIMAP_H))
		{
			i++;
			continue ;
		}
		mlx_pixel_put(data->mlx, data->win, pixel_col, i, data->map->floor_color);
		i++;
	}
}

void	c3_rycst_main(t_data *data)
{
	int		i;
	float	ray_angle;
	float	ray_dir_x;
	float	ray_dir_y;
	int		ray_pos_x;
	int		ray_pos_y;
	int		step_x;
	int		step_y;
	float	initial_x;
	float	initial_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	dist_x;
	float	dist_y;
	float	dist;
	float	angle_a;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		ray_angle = data->player->facing - (data->actual_fov / 2) + i * (data->actual_fov / WIN_WIDTH);
		ray_dir_x = cos(ray_angle);
		ray_dir_y = sin(ray_angle);
		ray_pos_x = data->player->x_pos;
		ray_pos_y = data->player->y_pos;
		if (ray_dir_x >= 0)
		{
			initial_x = fabs(data->player->x_pos - ceil(data->player->x_pos));
			step_x = 1;
		}
		if (ray_dir_x < 0)
		{
			initial_x = fabs(floor(data->player->x_pos) - data->player->x_pos);
			step_x = -1;
		}
		if (ray_dir_y >= 0)
		{
			initial_y = fabs(data->player->y_pos - ceil(data->player->y_pos));
			step_y = 1;
		}
		if (ray_dir_y < 0)
		{
			initial_y = fabs(floor(data->player->y_pos) - data->player->y_pos);
			step_y = -1;
		}
		delta_dist_x = fabs(1 / ray_dir_x);
		delta_dist_y = fabs(1 / ray_dir_y);
		dist_x = delta_dist_x * initial_x;
		dist_y = delta_dist_y * initial_y;
		while (1)
		{
			if (dist_x <= dist_y)
			{
				dist = dist_x;
				ray_pos_x += step_x;
				dist_x += delta_dist_x;
			}
			else
			{
				dist = dist_y;
				ray_pos_y += step_y;
				dist_y += delta_dist_y;
			}
			if (data->map->map[ray_pos_y][ray_pos_x] != 0)
			{
				angle_a = fabs(ray_angle - data->player->facing);
				if (angle_a > data->actual_fov / 2)
					angle_a -= (2 * PI);
				dist *= cos(angle_a);
				draw_line(data, i, dist);
				break ;
			}
		}
	}
}
