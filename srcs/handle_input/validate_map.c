/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:12:16 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/19 00:25:31 by ohaker           ###   ########.fr       */
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
	if (!map_temp)
		return (0);
	while (x < map->map_height && map_temp[x])
	{
		y = 0;
		while (y < map->map_width && map_temp[x][y] == NONE)
			y++;
		if (y >= map->map_width || map_temp[x][y] != WALL)
			return (printf("rows invalid: [%d][%d]\n", x, y), 0);
		y = map->map_width - 1;
		while (y >= 0 && map_temp[x][y] == NONE)
			y--;
		if (y < 0 || map_temp[x][y] != WALL)
			return (printf("rows invalid: [%d][%d]\n", x, y), 0);
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
	while (y < map->map_width)
	{
		x = 0;
		while (x < map->map_height && map_temp[x][y] == NONE)
			x++;
		if (x == map->map_height)
			break ;
		if (x > map->map_height || map_temp[x][y] != WALL)
			return (printf("cols invalid at x: '%d', y: '%d'\n", x, y), 0);
		x = map->map_height - 1;
		while (x >= 0 && map_temp[x][y] == NONE)
			x--;
		if (x < 0 || map_temp[x][y] != WALL)
			return (printf("cols invalid at x: '%d', y: '%d'\n", x, y), 0);
		y++;
	}
	printf("cols valid\n");
	return (1);
}

int	check_player(t_map *map)
{
	int	x;
	int	y;
	int	**map_temp;
	int	player_sig;

	x = 0;
	y = 0;
	map_temp = map->map;
	player_sig = 0;
	while (x < map->map_height)
	{
		y = 0;
		while (y < map->map_width)
		{
			if (map_temp[x][y] == PLAYER_N || map_temp[x][y] == PLAYER_E
				|| map_temp[x][y] == PLAYER_S || map_temp[x][y] == PLAYER_W)
				player_sig++;
			y++;
		}
		x++;
	}
	if (player_sig != 1)
		return (printf("invalid number of players [%d]\n", player_sig), 0);
	printf("player valid\n");
	return (1);
}

int	check_nones(t_map *map)
{
	int	x;
	int	y;

	if (!map || !map->map)
		return (0);
	x = 0;
	while (x < map->map_height)
	{
		y = 0;
		while (y < map->map_width)
		{
			if (map->map[x][y] == NONE)
				if (!valid_none(map, x, y))
					return (printf("invalid space at [%d][%d]\n", x, y), 0);
			y++;
		}
		x++;
	}
	printf("NONEs valid\n");
	return (1);
}

int	check_door(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map->map_width)
	{
		y = 0;
		while (y < data->map->map_height)
		{
			if (data->map->map[y][x] == DOOR && !data->map->tex_door)
				return (printf("Provide door texture\n"), 0);
			y++;
		}
		x++;
	}
	return (1);
}
