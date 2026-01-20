/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbarthol <pbarthol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:42:20 by pbarthol          #+#    #+#             */
/*   Updated: 2026/01/20 21:54:50 by pbarthol         ###   ########.fr       */
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

/**
 * Draws one vertical column for the current ray, filling ceiling, floor, or
 * textured wall pixels depending on the scanline position.
 *
 * @param data       - main game state and buffers
 * @param pixel_col  - screen x position being drawn
 * @param start      - top y coordinate of the wall slice
 * @param line_height- height of the wall slice in pixels
 */
void	c3_rycst_draw_line_loop(t_data *data, int pixel_col, int start,
	int line_height)
{
	int	i;
	int	clamped_start;
	int	clamped_end;

	clamped_start = start;
	clamped_end = start + line_height;
	if (clamped_start < 0)
		clamped_start = 0;
	if (clamped_end > WIN_HEIGHT)
		clamped_end = WIN_HEIGHT;
	i = -1;
	while (++i < WIN_HEIGHT)
	{
		if (i >= clamped_start && i < clamped_end)
			my_pixel_put(data->view, pixel_col, i, c3_rycst_find_text_pixel
				(data, (float)(i - start) / line_height));
		else if (i < WIN_HEIGHT / 2)
			my_pixel_put(data->view, pixel_col, i, data->map->ceiling_color);
		else
			my_pixel_put(data->view, pixel_col, i, data->map->floor_color);
	}
}

/**
 * Calculates wall projection height for a column, applies fisheye correction,
 * and delegates to the loop that paints ceiling, wall, and floor pixels.
 *
 * @param data      - main game state used for distances and buffers
 * @param pixel_col - screen x coordinate of the ray/wall slice
 */
void	c3_rycst_draw_line(t_data *data, int pixel_col)
{
	int		line_height;
	int		start;
	float	angle_a;

	angle_a = fabs(data->raycast->ray_angle - data->player->facing);
	if (angle_a > data->map->actual_fov / 2)
		angle_a -= (2 * PI);
	line_height = WIN_HEIGHT / (data->raycast->dist * cos(angle_a));
	start = (WIN_HEIGHT / 2) - (line_height / 2);
	c3_rycst_draw_line_loop(data, pixel_col, start, line_height);
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
	raycast->step_x = 0;
	raycast->step_y = 0;
	raycast->initial_x = 0;
	raycast->initial_y = 0;
	raycast->ray_dir_x = 0;
	raycast->ray_dir_y = 0;
	raycast->delta_dist_x = 0;
	raycast->delta_dist_y = 0;
	raycast->dist_x = 0;
	raycast->dist_y = 0;
	return (raycast);
}

/**
 * Moves the ray to the next grid boundary, tracks whether the hit was on a
 * vertical side, and triggers drawing when a wall or closed door is reached.
 *
 * @param data   - main game state containing ray data and map
 * @param i      - screen column index currently being processed
 * @return 0 when a blocking tile is hit (drawing performed), 1 to keep stepping
 */
void	c3_rycst_grid_step(t_data *data, int i)
{
	data->raycast->ray_angle = data->player->facing - (data->map->actual_fov
		/ 2) + i * (data->map->actual_fov / WIN_WIDTH);
	data->raycast->ray_dir_x = cos(data->raycast->ray_angle);
	data->raycast->ray_dir_y = sin(data->raycast->ray_angle);
	c3_rycst_initial_dist(data);
	data->raycast->delta_dist_x = fabs(1 / data->raycast->ray_dir_x);
	data->raycast->delta_dist_y = fabs(1 / data->raycast->ray_dir_y);
	if (data->raycast->dist_x <= data->raycast->dist_y)
	{
		data->raycast->dist = data->raycast->dist_x;
		data->raycast->ray_pos_x += data->raycast->step_x;
		data->raycast->dist_x += data->raycast->delta_dist_x;
		data->raycast->hit_vertical = 1;
	}
	else
	{
		data->raycast->dist = data->raycast->dist_y;
		data->raycast->ray_pos_y += data->raycast->step_y;
		data->raycast->dist_y += data->raycast->delta_dist_y;
		data->raycast->hit_vertical = 0;
	}
}

/**
 * Computes initial step direction and starting distances for both axes based
 * on the ray direction and the player's fractional position within the grid.
 *
 * @param data - main game state containing player position and ray data
 */
void	c3_rycst_initial_dist(t_data *data)
{
	if (data->raycast->ray_dir_x >= 0)
	{
		data->raycast->initial_x = fabs(data->player->x_pos - ceil(data->player
					->x_pos));
		data->raycast->step_x = 1;
	}
	if (data->raycast->ray_dir_x < 0)
	{
		data->raycast->initial_x = fabs(floor(data->player->x_pos) - data
				->player->x_pos);
		data->raycast->step_x = -1;
	}
	if (data->raycast->ray_dir_y >= 0)
	{
		data->raycast->initial_y = fabs(data->player->y_pos - ceil(data->player
					->y_pos));
		data->raycast->step_y = 1;
	}
	if (data->raycast->ray_dir_y < 0)
	{
		data->raycast->initial_y = fabs(floor(data->player->y_pos) - data
				->player->y_pos);
		data->raycast->step_y = -1;
	}
}

/**
 * Main raycasting loop: emits one ray per screen column, advances through the
 * grid until a wall or closed door is hit, then draws the projected slice.
 *
 * @param data - main game state containing map, player, and render targets
 */
void	c3_rycst_main(t_data *data)
{
	int		i;

	i = -1;
	if (data->view && data->view->addr)
		ft_bzero(data->view->addr, (size_t)data->view->line_len
			* (size_t)data->view->height);
	while (++i < WIN_WIDTH)
	{
		data->raycast->ray_pos_x = data->player->x_pos;
		data->raycast->ray_pos_y = data->player->y_pos;
		data->raycast->dist_x = data->raycast->delta_dist_x
			* data->raycast->initial_x;
		data->raycast->dist_y = data->raycast->delta_dist_y
			* data->raycast->initial_y;
		while (1)
		{
			c3_rycst_grid_step(data, i);
			if (data->map->map[data->raycast->ray_pos_y][data->raycast->ray_pos_x] == 1
				|| (data->map->map[data->raycast->ray_pos_y][data->raycast->ray_pos_x]
					== DOOR && !player_close_to_door(data)))
			{
				c3_rycst_draw_line(data, i);
				break ;
			}
		}
	}
}
