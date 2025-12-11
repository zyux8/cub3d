/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:12:16 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/11 19:04:28 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_rows(t_map *map)
{
	int	x;
	int	y;
	int	**map_temp;

	x = 0;
	map_temp = map->map;
	while (map_temp[x] && x < map->map_height)
	{
		y = 0;
		// printf("map[%d][%d]: '%d'\n", x, y, map_temp[x][y]);
		while (map_temp[x] && map_temp[x][y] == NONE)
			y++;
		if (map_temp[x] && map_temp[x][y] != WALL)
			return (printf("rows invalid\n"), 0);
		y = map->map_width - 1;
		while (map_temp[x] && map_temp[x][y] == NONE)
			y--;
		if (map_temp[x] && map_temp[x][y] != WALL)
			return (printf("rows invalid\n"), 0);
		x++;
	}
	printf("rows valid\n");
	return (1);
}

int	check_cols(t_map *map)
{
	int	x;
	int	y;
	int	**map_temp;

	x = 0;
	y = 0;
	map_temp = map->map;
	while (map_temp[x] && y < map->map_width)
	{
		x = 0;
		// printf("map[%d][%d]: '%d'\n", x, y, map_temp[x][y]);
		while (map_temp[x] && map_temp[x][y] == NONE)
			x++;
		if (map_temp[x] && map_temp[x][y] != WALL)
			return (printf("cols invalid\n"), 0);
		x = map->map_height - 1;
		while (map_temp[x] && map_temp[x][y] == NONE)
			x--;
		if (map_temp[x] && map_temp[x][y] != WALL)
			return (printf("cols invalid\n"), 0);
		y++;
	}
	printf("cols valid\n");
	return (1);
}

int	map_valid(t_data *data)
{
	int	x;

	x = 0;
	check_rows(data->map);
	check_cols(data->map);
	return (1);
	// check_player();
}
