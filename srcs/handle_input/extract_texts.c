/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:09:56 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/18 23:31:19 by ohaker           ###   ########.fr       */
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
		data->map->tex_floor = NULL;
	}
	else if (is_texture(lines, "F "))
	{
		p_f = get_single_text_path(lines, "F");
		if (!p_f)
			return (printf("extract_colors: one or more colors not found\n"),
				0);
		data->map->tex_floor = get_texture(data, p_f);
		if (!data->map->tex_floor)
			return (free(p_f),
				printf("extract_colors: failed to load floor texture\n"), 0);
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
		data->map->tex_ceiling = NULL;
	}
	else if (is_texture(lines, "C "))
	{
		p_c = get_single_text_path(lines, "C");
		if (!p_c)
			return (printf("extract_colors: one or more colors not found\n"),
				0);
		data->map->tex_ceiling = get_texture(data, p_c);
		if (!data->map->tex_ceiling)
		{
			free(p_c);
			printf("extract_colors: failed to load ceiling texture\n");
			return (0);
		}
		free(p_c);
	}
	return (1);
}

int	extract_bonus(t_data *data, char **lines)
{
	char	*p_do;

	if (!data || !lines)
		return (0);
	p_do = NULL;
	if (is_texture(lines, "DO "))
	{
		p_do = get_single_text_path(lines, "DO");
		if (!p_do)
			return (printf("extract_textures: missing door texture path\n"), 0);
		data->map->tex_door = get_texture(data, p_do);
		if (!data->map->tex_door)
		{
			free(p_do);
			printf("extract_textures: failed to load door texture\n");
			return (0);
		}
	}
	else
		data->map->tex_door = NULL;
	if (!data->mlx)
		return (free(p_do), printf("extract_textures: data->mlx is NULL\n"), 0);
	free(p_do);
	return (1);
}

int	extract_colors(t_data *data, char **lines)
{
	if (!data || !lines)
		return (0);
	if (!get_floor(data, lines))
		return (0);
	if (!get_ceiling(data, lines))
		return (0);
	if (is_texture(lines, "DO"))
		extract_bonus(data, lines);
	return (1);
}
