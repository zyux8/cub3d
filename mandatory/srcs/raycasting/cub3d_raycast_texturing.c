/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast_texturing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:28:15 by pbarthol          #+#    #+#             */
/*   Updated: 2026/01/22 22:15:58 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Selects the wall texture hit by the current ray based on impact side and
 * ray direction.
 *
 * @param data - main game state used to choose the correct texture
 * @return pointer to the selected texture (east, west, south, or north)
 */
t_img	*c3_rycst_assign_text(t_data *data)
{
	if (data->raycast->hit_vertical && cos(data->raycast->ray_angle) > 0)
		return (data->map->tex_east);
	else if (data->raycast->hit_vertical && cos(data->raycast->ray_angle) < 0)
		return (data->map->tex_west);
	else if (!data->raycast->hit_vertical && sin(data->raycast->ray_angle) > 0)
		return (data->map->tex_south);
	else
		return (data->map->tex_north);
}

/**
 * Computes the normalized wall coordinate (0.0 to 1.0) where the ray hits.
 * This decides which column of the chosen texture should be sampled.
 *
 * @param data - main game state containing ray metadata
 * @return normalized wall position in range [0.0, 1.0)
 */
float	c3_rycst_find_text_pixel_util(t_data *data)
{
	float	ray_pos;

	if (data->raycast->hit_vertical)
	{
		ray_pos = data->player->y_pos + (data->raycast->dist * sin(data->raycast
					->ray_angle));
		return (ray_pos - floor(ray_pos));
	}
	else
	{
		ray_pos = data->player->x_pos + (data->raycast->dist * cos(data->raycast
					->ray_angle));
		return (ray_pos - floor(ray_pos));
	}
}

/**
 * Samples the active wall texture at the ray hit point and applies distance
 * shading.
 *
 * @param data - main game state used for texture selection and ray data
 * @param i    - normalized vertical position within the projected wall slice
 * @return shaded RGB color as a 24-bit unsigned int
 */
unsigned int	c3_rycst_find_text_pixel(t_data *data, float i)
{
	float	wall_x;
	int		x_pixel_pos;
	int		y_pixel_pos;
	t_img	*texture;

	texture = c3_rycst_assign_text(data);
	wall_x = c3_rycst_find_text_pixel_util(data);
	x_pixel_pos = (int)(wall_x * texture->width);
	y_pixel_pos = (int)(i * texture->height);
	if (x_pixel_pos < 0)
		x_pixel_pos = 0;
	if (y_pixel_pos < 0)
		y_pixel_pos = 0;
	return (c3_rycst_shade(get_pixel_color(texture, x_pixel_pos, y_pixel_pos),
			data->raycast->dist));
}
