/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_even_more.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:47:58 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/10 21:52:13 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_single_text_path(char **lines, char *sig)
{
	int		x;
	char	*line;
	char	*path;

	x = 0;
	while (lines[x] && ft_strnstr(lines[x], sig, ft_strlen(lines[x])) == NULL)
		x++;
	line = ft_strnstr(lines[x], sig, ft_strlen(lines[x]));
	if (!line)
		return (NULL);
	if (ft_strncmp(line, sig, ft_strlen(sig)) == 0)
	{
		path = ft_strtrim(line + ft_strlen(sig), " ");
		path = ft_strtrim(path, "\n");
		printf("path: '%s'\n", path);
		return (path);
	}
	return (NULL);
}

void	malloc_map(int ***map, int height, int width)
{
	int	x;

	*map = malloc(sizeof(int *) * height);
	if (!*map)
		return ;
	x = 0;
	while (x < height)
	{
		(*map)[x] = malloc(sizeof(int) * width);
		x++;
	}
}

int	get_color(char **lines, char *sig)
{
	int		x;
	char	*line;
	int		rgb;
	char	**rgb_char;

	x = 0;
	while (lines[x] && ft_strnstr(lines[x], sig, ft_strlen(lines[x])) == NULL)
		x++;
	line = ft_strnstr(lines[x], sig, ft_strlen(lines[x]));
	if (!line)
		return (0);
	rgb_char = NULL;
	if (ft_strncmp(line, sig, ft_strlen(sig)) == 0)
	{
		line = ft_strtrim(line + ft_strlen(sig), " ");
		line = ft_strtrim(line, "\n");
		rgb_char = ft_split((const char *)line, ',');
	}
	if (!rgb_char)
		return (0);
	rgb = create_rgb(ft_atoi(rgb_char[0]), ft_atoi(rgb_char[1]),
			ft_atoi(rgb_char[2]));
	ft_free_split(rgb_char);
	printf("rgb: '%d'\n", rgb);
	return (rgb);
}
