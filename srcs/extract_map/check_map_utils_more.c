/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_more.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:40:36 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/10 21:45:36 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_data *data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return ;
	map->tex_north = NULL;
	map->tex_south = NULL;
	map->tex_west = NULL;
	map->tex_east = NULL;
	map->tex_ceiling = NULL;
	map->tex_floor = NULL;
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->map = NULL;
	map->player_facing = NONE;
	data->map = map;
}

int	start_of_map(char **lines)
{
	int	x;
	int	y;

	x = 6;
	while (lines[x])
	{
		y = 0;
		while (lines[x][y])
			if (lines[x][y++] == '1')
				break ;
		if (y != ft_strlen(lines[x]))
			break ;
		x++;
	}
	return (x);
}

void	copy_col(char *line, int *row, int width)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == ' ')
			row[x] = NONE;
		else if (line[x] == '0')
			row[x] = GROUND;
		else if (line[x] == '1')
			row[x] = WALL;
		else if (line[x] == 'N')
			row[x] = PLAYER_N;
		else if (line[x] == 'S')
			row[x] = PLAYER_S;
		else if (line[x] == 'E')
			row[x] = PLAYER_E;
		else if (line[x] == 'W')
			row[x] = PLAYER_W;
		x++;
	}
	while (x < width)
		row[x++] = NONE;
	row[x] = '\0';
}

int	get_height(char **lines, int start)
{
	int	x;

	x = start;
	while (lines[x])
		x++;
	printf("end of map: '%d'\n", x - start);
	return (x - start);
}

int	get_width(char **lines, int start)
{
	int	x;
	int	len;

	x = start;
	len = 0;
	while (lines[x])
	{
		if (ft_strlen(lines[x]) > len)
			len = ft_strlen(lines[x]);
		x++;
	}
	return (len - 1);
}
