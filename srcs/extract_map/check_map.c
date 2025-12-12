/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:10:49 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/12 19:52:00 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_textures(t_data *data, char **lines)
{
	char	*p_no;
	char	*p_so;
	char	*p_we;
	char	*p_ea;

	if (!data || !lines)
		return (0);
	init_map(data);
	p_no = get_single_text_path(lines, "NO");
	p_so = get_single_text_path(lines, "SO");
	p_we = get_single_text_path(lines, "WE");
	p_ea = get_single_text_path(lines, "EA");
	if (!p_no || !p_so || !p_we || !p_ea)
		return (free_paths(p_no, p_so, p_we, p_ea),
			printf("extract_textures: missing texture path(s)\n"), 0);
	if (!data->mlx)
		return (free_paths(p_no, p_so, p_we, p_ea),
			printf("extract_textures: data->mlx is NULL; call init_data(&data) first\n"),
			0);
	data->map->tex_north = get_texture(data, p_no);
	data->map->tex_south = get_texture(data, p_so);
	data->map->tex_west = get_texture(data, p_we);
	data->map->tex_east = get_texture(data, p_ea);
	free_paths(p_no, p_so, p_we, p_ea);
	return (1);
}

int	extract_colors(t_data *data, char **lines)
{
	int	fc;
	int	cc;

	fc = get_color(lines, "F ");
	cc = get_color(lines, "C ");
	if (!fc || !cc)
		return (printf("extract_colors: one or more colors not found\n"), 0);
	data->map->floor_color = fc;
	data->map->ceiling_color = cc;
	return (1);
}

void	print_map(int **map, int height, int width)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			printf("%d ", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

int	extract_map(t_data *data, char **lines)
{
	int	start;
	int	**map;
	int	y;

	start = start_of_map(lines);
	data->map->map_height = get_height(lines, start);
	data->map->map_width = get_width(lines, start);
	printf("height: '%d'\nwidth: '%d'\n", data->map->map_height,
		data->map->map_width);
	y = 0;
	malloc_map(&map, data->map->map_height, data->map->map_width);
	while (y < data->map->map_height)
	{
		copy_col(lines[start + y], map[y], data->map->map_width);
		y++;
	}
	print_map(map, data->map->map_height, data->map->map_width);
	data->map->map = map;
	return (1);
}

int	map_valid(t_map *map)
{
	if (!check_rows(map))
		return (0);
	if (!check_cols(map))
		return (0);
	if (!check_player(map))
		return (0);
	if (!check_nones(map))
		return (0);
	return (1);
}

int	check_map(char *filename, t_data *data)
{
	char	**lines;

	lines = malloc_lines((const char *)filename);
	if (!lines)
		return (0);
	if (!extract_textures(data, lines) || !extract_colors(data, lines))
		return (0);
	extract_map(data, lines);
	if (map_valid(data->map))
		return (0);
	return (1);
}

// has to be changed into new file for bonus and file parsing changed
// or if F and C doesnt exist look for the other from bonus(better)