/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:43:31 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/14 19:15:49 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cigar	*init_cigar(t_data *data)
{
	t_cigar	*cigar;
	int		fd1;
	int		fd2;

	cigar = malloc(sizeof(t_cigar));
	if (!cigar)
		return (NULL);
	fd1 = open("maps/textures/cigarre.xpm", R_OK);
	fd2 = open("maps/textures/smoke.xpm", R_OK);
	if (fd1 > 0 && fd2 > 0)
	{
		printf("found texts\n");
		cigar->cigar = get_texture(data, "maps/textures/cigarre.xpm");
		cigar->smoke = get_texture(data, "maps/textures/smoke.xpm");
	}
	else
		return (close(fd1), close(fd2), NULL);
	return (close(fd1), close(fd2), cigar);
}

static int	get_pixel_color(t_img *img, int x, int y)
{
	char	*dst;

	if (!img || !img->addr)
		return (0);
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

static void	overlay_image(t_img *dest, t_img *src, int x_off, int y_off)
{
	int	x;
	int	y;
	int	bg;
	int	col;

	if (!dest || !src)
		return ;
	bg = get_pixel_color(src, 0, 0);
	y = 0;
	while (y < src->height)
	{
		x = 0;
		while (x < src->width)
		{
			col = get_pixel_color(src, x, y);
			if (col != bg)
				my_pixel_put(dest, x_off + x, y_off + y, col);
			x++;
		}
		y++;
	}
}

int	load_cigar(t_data *data)
{
	if (data->keys->key_z)
	{
		if (data->cigar->cigar != NULL && data->cigar->smoke != NULL)
		{
			overlay_image(data->view, data->cigar->smoke, WIN_WIDTH - (WIN_WIDTH
					/ 2.7) + 20, WIN_HEIGHT - 900);
			overlay_image(data->view, data->cigar->cigar, WIN_WIDTH - (WIN_WIDTH
					/ 2.7), WIN_HEIGHT - 340);
		}
		else
			return (1);
	}
	return (0);
}
