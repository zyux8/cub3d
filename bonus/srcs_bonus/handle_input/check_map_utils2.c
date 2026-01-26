/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:16:45 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/26 14:20:00 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_isconfig(char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)
		|| !ft_strncmp(line, "DO", 2) || *line == 'F' || *line == 'C')
		return (1);
	return (0);
}

int	ft_is_empty_or_whitespace(char *line)
{
	if (!line)
		return (1);
	while (*line)
	{
		if (!ft_isspace(*line))
			return (0);
		line++;
	}
	return (1);
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

void	free_paths(char *p_no, char *p_so, char *p_we, char *p_ea)
{
	if (p_no)
		free(p_no);
	if (p_so)
		free(p_so);
	if (p_we)
		free(p_we);
	if (p_ea)
		free(p_ea);
}
