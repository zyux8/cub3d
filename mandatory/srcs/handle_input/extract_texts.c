/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:09:56 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/22 22:15:46 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_floor(t_data *data, char **lines)
{
	int		fc;

	if (!is_texture(lines, "F "))
	{
		fc = get_color(lines, "F ");
		if (!fc)
			return (printf("extract_colors: one or more colors not found\n"),
				0);
		data->map->floor_color = fc;
	}
	return (1);
}

int	extract_ceiling(t_data *data, char **lines)
{
	int		cc;

	if (!is_texture(lines, "C "))
	{
		cc = get_color(lines, "C ");
		if (!cc)
			return (printf("extract_colors: one or more colors not found\n"),
				0);
		data->map->ceiling_color = cc;
	}
	return (1);
}

int	extract_colors(t_data *data, char **lines)
{
	if (!data || !lines)
		return (0);
	if (!extract_floor(data, lines))
		return (0);
	if (!extract_ceiling(data, lines))
		return (0);
	return (1);
}

int	extract_textures(t_data *data, char **lines)
{
	char	*p_no;
	char	*p_so;
	char	*p_we;
	char	*p_ea;

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
			printf("extract_textures: data->mlx is NULL\n"), 0);
	data->map->tex_north = get_texture(data, p_no);
	data->map->tex_south = get_texture(data, p_so);
	data->map->tex_west = get_texture(data, p_we);
	data->map->tex_east = get_texture(data, p_ea);
	if (!data->map->tex_north || !data->map->tex_south || !data->map->tex_west
		|| !data->map->tex_east)
		return (free_paths(p_no, p_so, p_we, p_ea), 0);
	free_paths(p_no, p_so, p_we, p_ea);
	return (1);
}
