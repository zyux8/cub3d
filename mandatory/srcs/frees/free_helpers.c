/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:30:00 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/22 22:16:53 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_img(t_img *img, void *mlx)
{
	if (!img)
		return ;
	if (img->img && mlx)
	{
		mlx_destroy_image(mlx, img->img);
		img->img = NULL;
	}
	free(img);
}

void	free_player(t_playerpos *p)
{
	if (!p)
		return ;
	free(p);
}

void	free_keys(t_keys *k)
{
	if (!k)
		return ;
	free(k);
}

void	free_lines(char **lines)
{
	int	x;

	if (!lines)
		return ;
	x = 0;
	while (lines[x])
		free(lines[x++]);
	free(lines);
}
