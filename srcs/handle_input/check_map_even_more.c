/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_even_more.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:47:58 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/17 22:50:54 by ohaker           ###   ########.fr       */
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

t_playerpos	*init_player(int x, int y, int dir)
{
	t_playerpos	*player;
	double		angle;

	player = malloc(sizeof(t_playerpos));
	if (!player)
		return (NULL);
	player->x_pos = x + 0.5;
	player->y_pos = y + 0.5;
	if (dir == PLAYER_N)
		angle = 3.0 * PI / 2.0;
	else if (dir == PLAYER_S)
		angle = PI / 2.0;
	else if (dir == PLAYER_E)
		angle = 0.0;
	else if (dir == PLAYER_W)
		angle = PI;
	else
		angle = 0.0;
	player->facing = angle;
	return (player);
}

int	get_player_pos(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map->map_height)
	{
		y = 0;
		while (y < data->map->map_width)
		{
			if (data->map->map[x][y] >= PLAYER_N
				&& data->map->map[x][y] <= PLAYER_W)
				data->player = init_player(y, x, data->map->map[x][y]);
			y++;
		}
		x++;
	}
	printf("player; x: '%f', y: '%f', dir: '%f'\n", data->player->x_pos,
		data->player->y_pos, data->player->facing);
	return (1);
}
