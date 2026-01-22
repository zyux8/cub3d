/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:08:36 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/19 14:55:36 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	x;
	size_t	start;
	size_t	end;
	char	*strout;

	if (!str || !set)
		return (NULL);
	start = 0;
	while (str[start] && ft_strchr(set, str[start]))
		start++;
	end = ft_strlen(str);
	while (end > start && ft_strchr(set, str[end - 1]))
		end--;
	strout = malloc((end - start + 1) * sizeof(char));
	if (!strout)
		return (NULL);
	x = 0;
	while (start < end)
	{
		strout[x] = str[start];
		x++;
		start++;
	}
	strout[x] = '\0';
	return (strout);
}
/* Trims the beginning and end of the given string 'str'
	from the characters which are given in 'set'. */