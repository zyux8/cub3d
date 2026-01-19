/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbarthol <pbarthol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:42:20 by pbarthol          #+#    #+#             */
/*   Updated: 2026/01/19 19:43:03 by pbarthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*c3_rycst_assign_text(t_data *data, int hit_vertical, float ray_angle)
{
	if (hit_vertical && cos(ray_angle) > 0)
		return (data->map->tex_east);
	else if (hit_vertical && cos(ray_angle) < 0)
		return (data->map->tex_west);
	else if (!hit_vertical && sin(ray_angle) > 0)
		return (data->map->tex_south);
	else
		return (data->map->tex_north);
}

float	c3_rycst_find_text_pixel_util(t_data *data, float dist, float ray_angle,
	int hit_vertical)
{
	float	ray_pos;

	if (hit_vertical)
	{
		ray_pos = data->player->y_pos + (dist * sin(ray_angle));
		return (ray_pos - floor(ray_pos));
	}
	else
	{
		ray_pos = data->player->x_pos + (dist * cos(ray_angle));
		return (ray_pos - floor(ray_pos));
	}
}

unsigned int	c3_rycst_find_text_pixel(t_data *data, float i, float dist,
	float ray_angle, int hit_vertical)
{
	float	wall_x;
	int		x_pixel_pos;
	int		y_pixel_pos;
	t_img	*texture;

	texture = c3_rycst_assign_text(data, hit_vertical, ray_angle);
	wall_x = c3_rycst_find_text_pixel_util(data, dist, ray_angle, hit_vertical);
	x_pixel_pos = (int)(wall_x * texture->width);
	y_pixel_pos = (int)(i * texture->height);
	if (x_pixel_pos < 0)
		x_pixel_pos = 0;
	if (x_pixel_pos >= texture->width)
		x_pixel_pos = texture->width - 1;
	if (y_pixel_pos < 0)
		y_pixel_pos = 0;
	if (y_pixel_pos >= texture->height)
		y_pixel_pos = texture->height - 1;
	return (get_pixel_color(texture, x_pixel_pos, y_pixel_pos));
}

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

void	draw_line(t_data *data, int pixel_col, float dist, float ray_angle, int hit_vertical)
{
	int	i;
	int	line_height;
	int	start;
	int	end;

	if (dist < 1)
		line_height = WIN_HEIGHT;
	else
		line_height = WIN_HEIGHT / dist;
	i = 0;
	while (i < WIN_HEIGHT / 2)
	{
		if (!(pixel_col >= 20 && pixel_col < 20 + MINIMAP_W) || !(i >= 20
				&& i < 20 + MINIMAP_H))
			my_pixel_put(data->view, pixel_col, i, data->map->ceiling_color);
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		my_pixel_put(data->view, pixel_col, i, data->map->floor_color);
		i++;
	}
	start = (WIN_HEIGHT / 2) - (line_height / 2);
	end = start + line_height;
	if (start < 0)
		start = 0;
	if (end > WIN_HEIGHT)
		end = WIN_HEIGHT;
	i = start;
	while (i < end)
	{
		if (!(pixel_col >= 20 && pixel_col < 20 + MINIMAP_W) || !(i >= 20
				&& i < 20 + MINIMAP_H))
			my_pixel_put(data->view, pixel_col, i, c3_rycst_shade(c3_rycst_find_text_pixel(data, (i - start) / line_height, dist, ray_angle, hit_vertical), dist));
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
	int		hit_vertical;

	i = -1;
	ray_pos_y = 0;
	ray_pos_x = 0;
	if (data->view && data->view->addr)
		ft_bzero(data->view->addr, (size_t)data->view->line_len
			* (size_t)data->view->height);
	while (++i < WIN_WIDTH)
	{
		ray_angle = data->player->facing - (data->map->actual_fov / 2) + i
			* (data->map->actual_fov / WIN_WIDTH);
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
				hit_vertical = 1;
			}
			else
			{
				dist = dist_y;
				ray_pos_y += step_y;
				dist_y += delta_dist_y;
				hit_vertical = 0;
			}
			if (data->map->map[ray_pos_y][ray_pos_x] == 1
				|| (data->map->map[ray_pos_y][ray_pos_x] == DOOR
					&& !player_close_to_door(data)))
			{
				angle_a = fabs(ray_angle - data->player->facing);
				if (angle_a > data->map->actual_fov / 2)
					angle_a -= (2 * PI);
				dist *= cos(angle_a);
				draw_line(data, i, dist, ray_angle, hit_vertical);
				break ;
			}
		}
	}
}
