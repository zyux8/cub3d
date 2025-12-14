/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_more.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:40:36 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/14 01:52:34 by ohaker           ###   ########.fr       */
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

int	ft_isconfig(char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)
		|| !ft_strncmp(line, "DO", 2) || !ft_strncmp(line, "SP", 2)
		|| *line == 'F' || *line == 'C')
		return (1);
	return (0);
}

int	ft_is_empty_or_whitespace(char *line)
{
	if (!line)
		return (1);
	while (*line)
	{
		if (!ft_isspace(*line))
			return (0);
		line++;
	}
	return (1);
}

int	start_of_map(char **lines)
{
	int	x;

	x = 0;
	while (lines[x])
	{
		if (ft_is_empty_or_whitespace(lines[x]))
		{
			x++;
			continue ;
		}
		if (ft_isconfig(lines[x]))
		{
			x++;
			continue ;
		}
		return (x);
	}
	return (0);
}

void	copy_col(char *line, int *row, int width)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
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
		else if (line[x] == 'D')
			row[x] = DOOR;
		else if (line[x] == 'P')
			row[x] = SPRITE;
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
