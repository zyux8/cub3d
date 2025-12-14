/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_even_more.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:47:58 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/14 23:42:55 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_single_text_path(char **lines, char *sig)
{
	int		x;
	char	*line;
	char	*path;
	char	*path2;

	x = 0;
	while (lines[x] && ft_strnstr(lines[x], sig, ft_strlen(lines[x])) == NULL)
		x++;
	line = ft_strnstr(lines[x], sig, ft_strlen(lines[x]));
	if (!line)
		return (NULL);
	if (ft_strncmp(line, sig, ft_strlen(sig)) == 0)
	{
		path = ft_strtrim(line + ft_strlen(sig), " ");
		path2 = ft_strtrim(path, "\n");
		free(path);
		printf("path: '%s'\n", path2);
		return (path2);
	}
	return (NULL);
}

void	malloc_map(int ***map, int height, int width)
{
	int	x;

	*map = malloc(sizeof(int *) * (height + 1));
	if (!*map)
		return ;
	x = 0;
	while (x < height)
	{
		(*map)[x] = malloc(sizeof(int) * (width + 1));
		x++;
	}
}

int	get_color(char **lines, char *sig)
{
	int		x;
	char	*line;
	char	*line2;
	int		rgb;
	char	**rgb_char;

	x = 0;
	while (lines[x] && ft_strnstr(lines[x], sig, ft_strlen(lines[x])) == NULL)
		x++;
	line = ft_strnstr(lines[x], sig, ft_strlen(lines[x]));
	if (!line)
		return (0);
	if (ft_strncmp(line, sig, ft_strlen(sig)) == 0)
	{
		line = ft_strtrim(line + ft_strlen(sig), " ");
		line2 = ft_strtrim(line, "\n");
		free(line);
		rgb_char = ft_split((const char *)line2, ',');
		free(line2);
	}
	if (!rgb_char)
		return (0);
	rgb = create_rgb(ft_atoi(rgb_char[0]), ft_atoi(rgb_char[1]),
			ft_atoi(rgb_char[2]));
	printf("rgb: '%d'\n", rgb);
	return (ft_free_split(rgb_char), rgb);
}
