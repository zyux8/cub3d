/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 23:51:41 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/18 17:15:29 by ohaker           ###   ########.fr       */
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
