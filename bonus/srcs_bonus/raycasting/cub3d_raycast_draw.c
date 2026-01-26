/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:25:48 by pbarthol          #+#    #+#             */
/*   Updated: 2026/01/26 14:20:01 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
