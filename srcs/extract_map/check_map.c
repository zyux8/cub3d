/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:10:49 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/02 22:32:10 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_map(t_data *data)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL); //exit function
	map->map = NULL;
	map->player_facing = NULL;
	data->map = map;
}

int	extract_texture(t_data *data, char **lines)
{
	int	x;

	x = 0;
	init_map(&data);
	
}

int	check_map(char *filename, t_data *data)
{
	char	**lines;
	int		x;

	lines = malloc_lines((const char *)filename);
	if (!lines)
		return (0);
	x = 0;
	extract_textures(&data, lines);
	return (1);
	// open file \/
	// extract textures
	// extract colors
	// validate and save map
}
// tex_ptex_ptr = mlx_xpm_file_to_image(data.mlx, parsed_path_NO, &width,
// 		&height);tr = mlx_xpm_file_to_image(data.mlx, parsed_path_NO, &width,
// 		&height);