/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:27:15 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/19 17:16:19 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map_texts(t_map *map, void *mlx)
{
	if (map->tex_north)
		free_img(map->tex_north, mlx);
	if (map->tex_south)
		free_img(map->tex_south, mlx);
	if (map->tex_west)
		free_img(map->tex_west, mlx);
	if (map->tex_west)
		free_img(map->tex_east, mlx);
	if (map->tex_floor)
		free_img(map->tex_floor, mlx);
	if (map->tex_ceiling)
		free_img(map->tex_ceiling, mlx);
	if (map->tex_door)
		free_img(map->tex_door, mlx);
	if (map->tex_sprite)
		free_img(map->tex_sprite, mlx);
}

void	free_map(t_map *map, void *mlx)
{
	int	x;

	if (!map)
		return ;
	free_map_texts(map, mlx);
	if (map->map)
	{
		x = 0;
		while (x < map->map_height)
		{
			if (map->map[x])
				free(map->map[x]);
			x++;
		}
		free(map->map);
	}
	free(map);
}

void	cleanup_and_exit(t_data *data)
{
	if (!data)
		exit(0);
	if (data->view)
		free_img(data->view, data->mlx);
	if (data->minimap)
		free_minimap(data->minimap, data->mlx);
	if (data->map)
		free_map(data->map, data->mlx);
	if (data->player)
		free_player(data->player);
	if (data->keys)
		free_keys(data->keys);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}
