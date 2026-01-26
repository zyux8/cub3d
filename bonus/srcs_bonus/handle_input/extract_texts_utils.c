/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texts_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:23:15 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/26 14:20:00 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	valid_colors(char **rgb)
{
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[0]) < 0 || ft_strlen(rgb[0]) > 3)
		return (0);
	if (ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[1]) < 0 || ft_strlen(rgb[1]) > 3)
		return (0);
	if (ft_atoi(rgb[2]) > 255 || ft_atoi(rgb[2]) < 0 || ft_strlen(rgb[2]) > 3)
		return (0);
	return (1);
}

int	get_color(char **lines, char *sig)
{
	int		x;
	char	*line;
	char	*line2;
	char	**rgb_char;
	int		rgb;

	x = 0;
	while (lines[x] && ft_strnstr(lines[x], sig, ft_strlen(lines[x])) == NULL)
		x++;
	if (!lines[x])
		return (0);
	line = ft_strnstr(lines[x], sig, ft_strlen(lines[x]));
	if (!line)
		return (0);
	rgb_char = NULL;
	if (ft_strncmp(line, sig, ft_strlen(sig)) == 0)
	{
		line2 = ft_strtrim(line + ft_strlen(sig), " \n");
		rgb_char = ft_split((const char *)line2, ',');
	}
	if (!rgb_char || !valid_colors(rgb_char))
		return (free(line2), 0);
	rgb = create_rgb(ft_atoi(rgb_char[0]), ft_atoi(rgb_char[1]),
			ft_atoi(rgb_char[2]));
	return (free(line2), ft_free_split(rgb_char), rgb);
}

char	*get_single_text_path(char **lines, char *sig)
{
	int		x;
	char	*line;
	char	*path;
	char	*path2;

	x = 0;
	while (lines[x] && ft_strnstr(lines[x], sig, ft_strlen(lines[x])) == NULL)
		x++;
	if (!lines[x])
		return (NULL);
	line = ft_strnstr(lines[x], sig, ft_strlen(lines[x]));
	if (!line)
		return (NULL);
	if (ft_strncmp(line, sig, ft_strlen(sig)) == 0)
	{
		path = ft_strtrim(line + ft_strlen(sig), " ");
		path2 = ft_strtrim(path, "\n");
		free(path);
		return (path2);
	}
	return (NULL);
}

t_img	*get_texture(t_data *data, char *path)
{
	t_img	*texture;

	if (!data || !path)
		return (NULL);
	texture = ft_calloc(1, sizeof(t_img));
	if (!texture)
		return (NULL);
	texture->img = mlx_xpm_file_to_image(data->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
	{
		free(texture);
		printf("get_texture: failed to load image '%s'\n", path);
		return (NULL);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_len, &texture->endian);
	return (texture);
}

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
