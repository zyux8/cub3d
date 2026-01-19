/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay_smoke.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:33:07 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/19 19:45:48 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_smoke_texts(t_data *data, t_smoke *smoke)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;

	fd1 = 0;
	fd2 = 0;
	fd3 = 0;
	fd4 = 0;
	fd1 = open("maps/textures/smoke_01.xpm", R_OK);
	fd2 = open("maps/textures/smoke_02.xpm", R_OK);
	fd3 = open("maps/textures/smoke_03.xpm", R_OK);
	fd4 = open("maps/textures/smoke_04.xpm", R_OK);
	if (fd1 > 0 && fd2 > 0 && fd3 > 0 && fd4 > 0)
	{
		smoke->frames[0] = get_texture(data, "maps/textures/smoke_01.xpm");
		smoke->frames[1] = get_texture(data, "maps/textures/smoke_02.xpm");
		smoke->frames[2] = get_texture(data, "maps/textures/smoke_03.xpm");
		smoke->frames[3] = get_texture(data, "maps/textures/smoke_04.xpm");
	}
	else
		return (close(fd1), close(fd2), close(fd3), close(fd4), 0);
	return (close(fd1), close(fd2), close(fd3), close(fd4), 1);
}

int	init_smoke(t_data *data)
{
	t_smoke	*smoke;

	smoke = malloc(sizeof(t_smoke));
	if (!data || !smoke)
		return (0);
	smoke->frame_count = 4;
	smoke->current = 0;
	smoke->frames = malloc(sizeof(t_img) * smoke->frame_count);
	if (!smoke->frames || !load_smoke_texts(data, smoke))
		return (0);
	smoke->frame_delay = 500;
	data->cigar->smoke = smoke;
	return (1);
}
