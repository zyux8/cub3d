/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:03:30 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/02 22:04:14 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_lines(const char filename)
{
	int		fd;
	int		x;
	char	*line;

	x = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (line = get_next_line(fd) != NULL)
	{
		x++;
		free(line);
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

	line_cnt = count_lines(filename);
	if (line_cnt < 0)
		return (NULL);
	lines = malloc((line_cnt + 1) * sizeof(char *));
	if (!lines)
		return (NULL);
	x = 0;
	fd = open(filename, O_RDONLY);
	while (lines[x] = get_next_line(fd) != NULL)
		x++;
	close(fd);
	return (lines);
}
