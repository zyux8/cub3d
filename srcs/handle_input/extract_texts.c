/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:09:56 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/19 17:06:40 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_texture(char **lines, char *sig)
{
	int	x;

	x = 0;
	while (lines[x] && ft_strnstr(lines[x], sig, ft_strlen(lines[x])) == NULL)
		x++;
	if (lines[x] && ft_strnstr(lines[x], ".xpm", ft_strlen(lines[x])) != NULL)
		return (1);
	return (0);
}

int	get_floor(t_data *data, char **lines)
{
	int		fc;
	char	*p_f;

	if (!is_texture(lines, "F "))
	{
		fc = get_color(lines, "F ");
		if (!fc)
			return (printf("extract_colors: one or more colors not found\n"),
				0);
		data->map->floor_color = fc;
	}
	else if (is_texture(lines, "F "))
	{
		p_f = get_single_text_path(lines, "F");
		if (!p_f)
			return (printf("extract_colors: one or more colors not found\n"),
				0);
		data->map->tex_floor = get_texture(data, p_f);
		free(p_f);
	}
	return (1);
}

int	get_ceiling(t_data *data, char **lines)
{
	int		cc;
	char	*p_c;

	if (!is_texture(lines, "C "))
	{
		cc = get_color(lines, "C ");
		if (!cc)
			return (printf("extract_colors: one or more colors not found\n"),
				0);
		data->map->ceiling_color = cc;
	}
	else if (is_texture(lines, "C "))
	{
		p_c = get_single_text_path(lines, "C");
		if (!p_c)
			return (printf("extract_colors: one or more colors not found\n"),
				0);
		data->map->tex_ceiling = get_texture(data, p_c);
		free(p_c);
	}
	return (1);
}

int	extract_bonus(t_data *data, char **lines)
{
	char	*p_do;
	char	*p_sp;

	if (!data || !lines)
		return (0);
	if (is_texture(lines, "DO "))
	{
		p_do = get_single_text_path(lines, "DO");
		if (!p_do)
			return (free(p_do),
				printf("extract_textures: missing texture path(s)\n"), 0);
		data->map->tex_door = get_texture(data, p_do);
	}
	if (is_texture(lines, "SP "))
	{
		p_sp = get_single_text_path(lines, "SP");
		if (!p_sp)
			return (free_paths(NULL, NULL, p_do, p_sp),
				printf("extract_textures: missing texture path(s)\n"), 0);
		data->map->tex_sprite = get_texture(data, p_sp);
	}
	if (!data->mlx)
		return (free_paths(NULL, NULL, p_do, p_sp),
			printf("extract_textures: data->mlx is NULL\n"), 0);
	return (free_paths(NULL, NULL, p_do, p_sp), 1);
}

int	extract_colors(t_data *data, char **lines)
{
	if (!data || !lines)
		return (0);
	if (!get_floor(data, lines))
		return (0);
	if (!get_ceiling(data, lines))
		return (0);
	if (is_texture(lines, "DO") || is_texture(lines, "SP"))
		extract_bonus(data, lines);
	return (1);
}
