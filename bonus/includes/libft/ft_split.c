/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:36:59 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/23 16:23:12 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *str, size_t x)
{
	char	*astr;

	astr = (char *)malloc(sizeof(char) * (x + 1));
	if (!astr)
		return (NULL);
	astr = ft_strncpy(astr, str, x);
	astr[x] = '\0';
	return (astr);
}

void	free_allocated(char **newstr, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(newstr[i]);
		i++;
	}
	free(newstr);
}

int	ft_split_words(char const *str, char c, char **newstr)
{
	size_t	x;
	size_t	y;
	size_t	z;

	x = 0;
	z = 0;
	while (str[x])
	{
		while (str[x] == c)
			x++;
		y = x;
		while (str[x] && str[x] != c)
			x++;
		if (x > y)
		{
			newstr[z] = ft_strndup(str + y, x - y);
			if (!newstr[z])
				return (free_allocated(newstr, z), 0);
			z++;
		}
	}
	newstr[z] = NULL;
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**newstr;

	newstr = (char **)malloc(sizeof(char *) * (ft_count_words(str, c) + 1));
	if (!newstr)
		return (NULL);
	if (!ft_split_words(str, c, newstr))
		return (NULL);
	return (newstr);
}
/* Returns an array of strings obtained by splitting the string 'str' using
	the character 'c' as a delimiter. */