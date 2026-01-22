/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:31:04 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/02 20:21:21 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_read_line(int fd)
// {
// 	char	*buffer;
// 	char	*result;
// 	int		bytes_read;
// 	char	*tmp;

// 	result = malloc(1);
// 	if (!result)
// 		return (NULL);
// 	result[0] = '\0';
// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (free(result), NULL);
// 	while (1)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read < 0)
// 			return (free(result), free(buffer), NULL);
// 		if (bytes_read == 0)
// 			break ;
// 		buffer[bytes_read] = '\0';
// 		tmp = ft_strjoin(result, buffer);
// 		free(result);
// 		result = tmp;
// 		if (!result)
// 			return (free(buffer), NULL);
// 		if (ft_strchr(buffer, '\n'))
// 			break ;
// 	}
// 	return (free(buffer), result);
// }

static char	*ft_read_to_str(int fd, char *result, char *buffer)
{
	int		bytes_read;
	char	*tmp;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(result), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(result, buffer);
		free(result);
		result = tmp;
		if (!result)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (result);
}

char	*ft_read_line(int fd)
{
	char	*buffer;
	char	*result;

	result = malloc(1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(result), NULL);
	result = ft_read_to_str(fd, result, buffer);
	free(buffer);
	return (result);
}

char	*ft_get_line(char *str)
{
	int		x;
	char	*buffer;

	if (!str || !*str)
		return (NULL);
	x = 0;
	while (str[x] && str[x] != '\n')
		x++;
	if (str[x] == '\n')
		x++;
	buffer = malloc(x + 1);
	if (!buffer)
		return (NULL);
	x = 0;
	while (str[x] && str[x] != '\n')
	{
		buffer[x] = str[x];
		x++;
	}
	if (str[x] == '\n')
		buffer[x++] = '\n';
	buffer[x] = '\0';
	return (buffer);
}

char	*get_left(char *str)
{
	int		x;
	int		y;
	char	*line;
	int		len;

	if (!str)
		return (free(str), NULL);
	len = ft_strlen(str);
	x = 0;
	while (str[x] && str[x] != '\n')
		x++;
	if (str[x] == '\n')
		x++;
	if (x >= len)
		return (free(str), NULL);
	line = malloc(len - x + 1);
	if (!line)
		return (NULL);
	y = 0;
	while (str[x])
		line[y++] = str[x++];
	line[y] = '\0';
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*new_data;
	static char	*leftover;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_data = ft_read_line(fd);
	if ((!new_data && BUFFER_SIZE < 100) || (!new_data && !leftover))
	{
		leftover = get_left(leftover);
		return (NULL);
	}
	if (!leftover)
		leftover = ft_strdup(new_data);
	else
	{
		tmp = ft_strjoin(leftover, new_data);
		free(leftover);
		leftover = tmp;
	}
	free(new_data);
	line = ft_get_line(leftover);
	leftover = get_left(leftover);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("/home/ohaker/Projects/get_next_line/test.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Line: %s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
