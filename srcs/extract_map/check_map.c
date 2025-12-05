/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:10:49 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/05 17:59:47 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_data *data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL); // exit function
	map->map = NULL;
	map->player_facing = NULL;
	data->map = map;
}

char	*get_single_text(char **lines, char *sig)
{
	int		x;
	char	*line;
	int		y;
	
	x = 0;
	while (ft_strnstr(lines[x], sig, ft_strlen(lines[x])) == NULL)
	x++;
	line = ft_strnstr(lines[x], sig, ft_strlen(lines[x]));
	y = 0;
	
	while (ft_isspace(line[y]))
		y++;
	
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