/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbarthol <pbarthol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:42:20 by pbarthol          #+#    #+#             */
/*   Updated: 2026/01/20 18:44:35 by pbarthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Calculates a distance-based shading effect for a given RGB color.
 * Colors appear darker the farther they are from the viewer.
 *
 * @param color - 24-bit RGB color encoded in a single unsigned int
 * @param dist  - distance value used to derive the shading factor
 * @return the shaded RGB color encoded as a 24-bit unsigned int
 *
 * The input color is decomposed into its red, green, and blue channels using
 * bit shifts:
 *   red   = 0xXX0000
 *   green = 0x00XX00
 *   blue  = 0x0000XX
 *
 * A shading factor is computed as 1 / dist. Because values greater than 1 would
 * brighten the color instead of darkening it, the factor is limited to 1. Each
 * channel is multiplied by the final factor to reduce intensity while
 * preserving the color balance. The darkened channels are then recombined into
 * a single 24-bit RGB color value and returned.
 */

unsigned int	c3_rycst_shade(unsigned int color, float dist)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	float			shade;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	shade = 1 / dist;
	if (shade > 1)
		shade = 1;
	else if (shade < MAX_SHADING)
		shade = MAX_SHADING;
	r = (unsigned char)(r * shade);
	g = (unsigned char)(g * shade);
	b = (unsigned char)(b * shade);
	return ((r << 16) | (g << 8) | b);
}

void	c3_rycst_draw_line(t_data *data, int pixel_col)
{
	int		i;
	int		line_height;
	int		start;
	int		end;
	int		clamped_start;
	int		clamped_end;
	int		texture_offset;
	float	angle_a;

	angle_a = fabs(data->raycast->ray_angle - data->player->facing);
	if (angle_a > data->map->actual_fov / 2)
		angle_a -= (2 * PI);
	line_height = WIN_HEIGHT / (data->raycast->dist * cos(angle_a));
	i = -1;
	while (++i < WIN_HEIGHT)
	{
		if (i < WIN_HEIGHT / 2)
			my_pixel_put(data->view, pixel_col, i, data->map->ceiling_color);
		else
			my_pixel_put(data->view, pixel_col, i, data->map->floor_color);
	}
	start = (WIN_HEIGHT / 2) - (line_height / 2);
	end = start + line_height;
	clamped_start = start;
	clamped_end = end;
	texture_offset = 0;
	if (clamped_start < 0)
	{
		texture_offset = (float)(-clamped_start) / line_height;
		clamped_start = 0;
	}
	if (clamped_end > WIN_HEIGHT)
		clamped_end = WIN_HEIGHT;
	i = clamped_start;
	while (i < clamped_end)
	{
		if (!(pixel_col >= 20 && pixel_col < 20 + MINIMAP_W) || !(i >= 20
				&& i < 20 + MINIMAP_H))
			my_pixel_put(data->view, pixel_col, i, c3_rycst_find_text_pixel
				(data, (float)(i - start) / line_height));
		i++;
	}
}

/**
 * Allocates and initializes the per-frame raycasting state.
 * Fields are set to neutral defaults so callers can immediately update them
 * for each cast ray.
 *
 * @return pointer to a cleared raycast state, or NULL on allocation failure
 */
t_raycast	*init_raycast(void)
{
	t_raycast	*raycast;

	raycast = malloc(sizeof(t_raycast));
	if (!raycast)
		return (NULL);
	raycast->ray_angle = 0;
	raycast->dist = 0;
	raycast->hit_vertical = 0;
	return (raycast);
}

void	c3_rycst_main(t_data *data)
{
	int		i;
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

	i = -1;
	ray_pos_y = 0;
	ray_pos_x = 0;
	if (data->view && data->view->addr)
		ft_bzero(data->view->addr, (size_t)data->view->line_len
			* (size_t)data->view->height);
	while (++i < WIN_WIDTH)
	{
		data->raycast->ray_angle = data->player->facing - (data->map->actual_fov / 2) + i
			* (data->map->actual_fov / WIN_WIDTH);
		ray_dir_x = cos(data->raycast->ray_angle);
		ray_dir_y = sin(data->raycast->ray_angle);
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
				data->raycast->dist = dist_x;
				ray_pos_x += step_x;
				dist_x += delta_dist_x;
				data->raycast->hit_vertical = 1;
			}
			else
			{
				data->raycast->dist = dist_y;
				ray_pos_y += step_y;
				dist_y += delta_dist_y;
				data->raycast->hit_vertical = 0;
			}
			if (data->map->map[ray_pos_y][ray_pos_x] == 1
				|| (data->map->map[ray_pos_y][ray_pos_x] == DOOR
					&& !player_close_to_door(data)))
			{
				c3_rycst_draw_line(data, i);
				break ;
			}
		}
	}
}
