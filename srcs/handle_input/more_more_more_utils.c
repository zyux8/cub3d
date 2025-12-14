/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_more_more_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:31:48 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/14 21:32:33 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isconfig(char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)
		|| !ft_strncmp(line, "DO", 2) || !ft_strncmp(line, "SP", 2)
		|| *line == 'F' || *line == 'C')
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

void	assign_pos(int *c, char sig)
{
	if (sig == ' ')
		*c = NONE;
	else if (sig == '0')
		*c = GROUND;
	else if (sig == '1')
		*c = WALL;
	else if (sig == 'N')
		*c = PLAYER_N;
	else if (sig == 'S')
		*c = PLAYER_S;
	else if (sig == 'E')
		*c = PLAYER_E;
	else if (sig == 'W')
		*c = PLAYER_W;
	else if (sig == 'D')
		*c = DOOR;
	else if (sig == 'P')
		*c = SPRITE;
}

void	copy_col(char *line, int *row, int width)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		assign_pos(&row[x], line[x]);
		x++;
	}
	while (x < width)
		row[x++] = NONE;
	row[x] = '\0';
}
