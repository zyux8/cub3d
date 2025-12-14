/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:12:16 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/14 01:52:16 by ohaker           ###   ########.fr       */
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
		while (map_temp[x] && map_temp[x][y] == NONE)
			y++;
		if (map_temp[x] && map_temp[x][y] != WALL)
			return (printf("rows invalid: [%d][%d]\n", x, y), 0);
		y = map->map_width - 1;
		while (map_temp[x] && map_temp[x][y] == NONE)
			y--;
		if (map_temp[x] && map_temp[x][y] != WALL)
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
	while (map_temp[x] && y < map->map_width)
	{
		x = 0;
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

int	valid_none(t_map *map, int x, int y)
{
	int	**tmap;

	if (!map || !map->map)
		return (0);
	tmap = map->map;
	if (x < 0 || x > map->map_height || y < 0 || y > map->map_width)
		return (printf("here\n"), 0);
	if (y - 1 >= 0 && (tmap[x][y - 1] == GROUND || (tmap[x][y - 1] >= PLAYER_N
				&& tmap[x][y - 1] <= PLAYER_W)))
		return (0);
	if (y + 1 < map->map_width && (tmap[x][y + 1] == GROUND || (tmap[x][y
				+ 1] >= PLAYER_N && tmap[x][y + 1] <= PLAYER_W)))
		return (0);
	if (x - 1 >= 0 && (tmap[x - 1][y] == GROUND || (tmap[x - 1][y] >= PLAYER_N
				&& tmap[x - 1][y] <= PLAYER_W)))
		return (0);
	if (x + 1 < map->map_height && (tmap[x + 1][y] == GROUND || (tmap[x
				+ 1][y] >= PLAYER_N && tmap[x + 1][y] <= PLAYER_W)))
		return (0);
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
