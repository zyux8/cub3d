/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:09:56 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/13 18:05:09 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_colors(t_data *data, char **lines)
{
	int		fc;
	int		cc;
	char	*F;
	char	*C;

	if (!data || !lines)
		return (0);
	if (!is_texture(lines, "F "))
	{
		fc = get_color(lines, "F ");
		cc = get_color(lines, "C ");
		if (!fc || !cc)
			return (printf("extract_colors: one or more colors not found\n"),
				0);
		data->map->floor_color = fc;
		data->map->ceiling_color = cc;
	}
	else if (is_texture(lines, "F "))
	{
		F = get_single_text_path(lines, "F");
		C = get_single_text_path(lines, "C");
		if (!F || !C)
			return (printf("extract_colors: one or more colors not found\n"),
				0);
		data->map->tex_floor = get_texture(data, F);
		data->map->tex_ceiling = get_texture(data, C);
	}
	return (1);
}

// extract colors needs to be splitted into F and C

int	extract_bonus(t_data *data, char **lines)
{
	char	*DO;
	char	*SP;

	if (!data || !lines)
		return (0);
	DO = get_single_text_path(lines, "DO");
	SP = get_single_text_path(lines, "SP");
	if (!DO || !SP)
		return (free_paths(NULL, NULL, DO, SP),
			printf("extract_textures: missing texture path(s)\n"), 0);
	if (!data->mlx)
		return (free_paths(NULL, NULL, DO, SP),
			printf("extract_textures: data->mlx is NULL\n"), 0);
	data->map->tex_door = get_texture(data, DO);
	data->map->tex_sprite = get_texture(data, SP);
	free_paths(NULL, NULL, DO, SP);
	return (1);
}

int	is_texture(char **lines, char *sig)
{
	int		x;
	char	*line;

	x = 0;
	while (lines[x] && ft_strnstr(lines[x], sig, ft_strlen(lines[x])) == NULL)
		x++;
	if (lines[x] && ft_strnstr(lines[x], ".xpm", ft_strlen(lines[x])) == NULL)
		return (1);
	return (0);
}
