/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:18:15 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/19 00:20:03 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_pos(int *c, char sig)
{
	if (sig == ' ')
		*c = NONE;
	else if (sig == '0')
		*c = GROUND;
	else if (sig == '1')
		*c = WALL;
	else if (sig == 'N')
		*c = PLAYER_N;
	else if (sig == 'S')
		*c = PLAYER_S;
	else if (sig == 'E')
		*c = PLAYER_E;
	else if (sig == 'W')
		*c = PLAYER_W;
	else if (sig == 'D')
		*c = DOOR;
	else if (sig == 'P')
		*c = SPRITE;
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

void	copy_col(char *line, int *row, int width)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		assign_pos(&row[x], line[x]);
		x++;
	}
	while (x < width)
		row[x++] = NONE;
	row[x] = '\0';
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
		copy_col(lines[start + x], map[x], data->map->map_width);
		x++;
	}
	data->map->map = map;
	return (1);
}
