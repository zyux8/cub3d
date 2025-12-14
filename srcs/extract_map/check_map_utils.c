/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:03:30 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/14 01:23:58 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_lines(const char *filename)
{
	int		fd;
	int		x;
	char	*line;

	x = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
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

	printf("'%s'\n", filename);
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
	while ((lines[x] = get_next_line(fd)) != NULL)
		x++;
	close(fd);
	lines[x] = NULL;
	return (lines);
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

int	is_map_char(char c)
{
	// if (!c)
	// 	return (0);
	return (c == ' ' || c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == 'D' || c == 'P');
}

t_texture	*get_texture(t_data *data, char *path)
{
	t_texture	*texture;

	if (!data || !path)
		return (NULL);
	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->img_ptr = mlx_xpm_file_to_image(data->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img_ptr)
	{
		free(texture);
		printf("get_texture: failed to load image '%s'\n", path);
		return (NULL);
	}
	texture->addr = mlx_get_data_addr(texture->img_ptr,
			&texture->bits_per_pixel, &texture->line_len, &texture->endian);
	return (texture);
}
