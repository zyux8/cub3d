/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:18:15 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/22 22:09:43 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	assign_pos(int *c, char sig)
{
	if (sig == ' ')
		return (*c = NONE, 1);
	else if (sig == '0')
		return (*c = GROUND, 1);
	else if (sig == '1')
		return (*c = WALL, 1);
	else if (sig == 'N')
		return (*c = PLAYER_N, 1);
	else if (sig == 'S')
		return (*c = PLAYER_S, 1);
	else if (sig == 'E')
		return (*c = PLAYER_E, 1);
	else if (sig == 'W')
		return (*c = PLAYER_W, 1);
	else
		return (printf("Extra map character detected"), 0);
	return (0);
}

int	get_player_pos(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map->map_height)
	{
		y = 0;
		while (y < data->map->map_width)
		{
			if (data->map->map[x][y] >= PLAYER_N
				&& data->map->map[x][y] <= PLAYER_W && data->player == NULL)
				data->player = init_player(y, x, data->map->map[x][y]);
			y++;
		}
		x++;
	}
	return (1);
}

int	is_map_char(char c)
{
	return (c == ' ' || c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == 'D');
}

int	copy_col(char *line, int *row, int width)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		if (!assign_pos(&row[x], line[x]))
			return (0);
		x++;
	}
	while (x < width)
		row[x++] = NONE;
	row[x] = '\0';
	return (1);
}

int	extract_map(t_data *data, char **lines)
{
	int	start;
	int	**map;
	int	x;

	start = start_of_map(lines);
	data->map->map_height = get_height(lines, start);
	data->map->map_width = get_width(lines, start);
	x = 0;
	malloc_map(&map, data->map->map_height, data->map->map_width);
	while (x < data->map->map_height)
	{
		if (!copy_col(lines[start + x], map[x], data->map->map_width))
			return (0);
		x++;
	}
	data->map->map = map;
	return (1);
}
