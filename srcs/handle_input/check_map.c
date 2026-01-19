/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbarthol <pbarthol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:10:49 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/19 21:11:00 by pbarthol         ###   ########.fr       */
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
	map->tex_ceiling = NULL;
	map->tex_floor = NULL;
	map->map = NULL;
	map->map_height = 0;
	map->map_width = 0;
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->player_facing = NONE;
	map->actual_fov = FOV * (PI / 180);
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

int	map_valid(t_data *data)
{
	if (!check_door(data))
		return (0);
	if (!check_rows(data->map))
		return (0);
	if (!check_cols(data->map))
		return (0);
	if (!check_player(data->map))
		return (0);
	if (!check_nones(data->map))
		return (0);
	return (1);
}

int	check_map(int ac, char **av, t_data *data)
{
	char	**lines;
	int		x;
	int		fd;

	if (ac < 2 || !ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
		return (printf("Usage: './cub3d' <map.cub>\n"), 0);
	fd = open(av[1], R_OK);
	if (fd <= 0)
		return (printf("File couldnt be opened/found\n"), close(fd), 0);
	close(fd);
	init_data(data);
	lines = malloc_lines((const char *)av[1]);
	if (!lines)
		return (0);
	if (!extract_textures(data, lines) || !extract_colors(data, lines))
		return (0);
	extract_map(data, lines);
	x = 0;
	while (lines[x])
		free(lines[x++]);
	free(lines);
	if (!map_valid(data))
		return (0);
	get_player_pos(data);
	return (1);
}
