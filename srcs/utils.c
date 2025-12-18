/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:34:48 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/17 22:46:19 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (!img || !img->addr)
		return ;
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

t_keys	*init_key_struct(void)
{
	t_keys	*key;

	key = malloc(sizeof(t_keys));
	if (!key)
		return (NULL);
	key->key_up = 0;
	key->key_do = 0;
	key->key_ri = 0;
	key->key_le = 0;
	return (key);
}
