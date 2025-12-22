/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_even_more.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:47:58 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/22 20:01:50 by ohaker           ###   ########.fr       */
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
		return (path2);
	}
	return (NULL);
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
				&& data->map->map[x][y] <= PLAYER_W && data->player == NULL)
				data->player = init_player(y, x, data->map->map[x][y]);
			y++;
		}
		x++;
	}
	return (1);
}
