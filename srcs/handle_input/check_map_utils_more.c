/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_more.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:40:36 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/22 19:17:05 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_data *data)
{
	t_map	*map;

	data->map = NULL;
	map = malloc(sizeof(t_map));
	if (!map)
		return ;
	map->tex_north = NULL;
	map->tex_south = NULL;
	map->tex_west = NULL;
	map->tex_east = NULL;
	map->tex_door = NULL;
	map->tex_sprite = NULL;
	map->tex_ceiling = NULL;
	map->tex_floor = NULL;
	map->map = NULL;
	map->map_height = 0;
	map->map_width = 0;
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->player_facing = NONE;
	data->map = map;
}

int	get_height(char **lines, int start)
{
	int	x;

	x = start;
	while (lines[x])
		x++;
	return (x - start);
}

int	get_width(char **lines, int start)
{
	int	x;
	int	width;

	x = start;
	width = 0;
	while (lines[x])
	{
		if (ft_strlen(lines[x]) > width)
			width = ft_strlen(lines[x]);
		x++;
	}
	return (width - 1);
}
