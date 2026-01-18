/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:03:30 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/19 00:24:17 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_none(t_map *map, int x, int y)
{
	int	**tmap;

	if (!map || !map->map)
		return (0);
	tmap = map->map;
	if (x < 0 || x > map->map_height || y < 0 || y > map->map_width)
		return (0);
	if (y - 1 >= 0 && (tmap[x][y - 1] == GROUND || (tmap[x][y - 1] >= PLAYER_N
		&& tmap[x][y - 1] <= PLAYER_W)))
		return (0);
	if (y + 1 < map->map_width && (tmap[x][y + 1] == GROUND
		|| (tmap[x][y + 1] >= PLAYER_N && tmap[x][y + 1] <= PLAYER_W)))
		return (0);
	if (x - 1 >= 0 && (tmap[x - 1][y] == GROUND || (tmap[x - 1][y] >= PLAYER_N
		&& tmap[x - 1][y] <= PLAYER_W)))
		return (0);
	if (x + 1 < map->map_height && (tmap[x + 1][y] == GROUND
		|| (tmap[x + 1][y] >= PLAYER_N && tmap[x + 1][y] <= PLAYER_W)))
		return (0);
	return (1);
}

void	malloc_map(int ***map, int height, int width)
{
	int	x;

	*map = ft_calloc((size_t)height + 1, sizeof(int *));
	if (!*map)
		return ;
	x = 0;
	while (x < height)
	{
		(*map)[x] = ft_calloc((size_t)width + 1, sizeof(int));
		if (!(*map)[x])
		{
			while (--x >= 0)
				free((*map)[x]);
			free(*map);
			*map = NULL;
			return ;
		}
		x++;
	}
	(*map)[height] = NULL;
}

int	count_lines(const char *filename)
{
	int		fd;
	int		x;
	char	*line;

	x = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		x++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (x);
}

char	**malloc_lines(const char *filename)
{
	int		line_cnt;
	char	**lines;
	int		x;
	int		fd;

	if (!filename)
		return (printf("invalid file\n"), NULL);
	if (!ft_strnstr(filename, ".cub", ft_strlen(filename)))
		return (printf("invalid file\n"), NULL);
	line_cnt = count_lines(filename);
	if (line_cnt < 0)
		return (NULL);
	lines = malloc((line_cnt + 1) * sizeof(char *));
	if (!lines)
		return (NULL);
	x = 0;
	fd = open(filename, O_RDONLY);
	lines[x] = get_next_line(fd);
	while (lines[x] != NULL)
		lines[++x] = get_next_line(fd);
	close(fd);
	lines[x] = NULL;
	return (lines);
}

int	start_of_map(char **lines)
{
	int	x;

	x = 0;
	while (lines[x])
	{
		if (ft_is_empty_or_whitespace(lines[x]))
		{
			x++;
			continue ;
		}
		if (ft_isconfig(lines[x]))
		{
			x++;
			continue ;
		}
		return (x);
	}
	return (0);
}
