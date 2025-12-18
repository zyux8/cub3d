/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 23:51:41 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/18 00:51:50 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_minimap_pixel(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < MINIMAP_W && y >= 0 && y < MINIMAP_H)
		my_pixel_put(img, x + 20, y + 20, color);
}
