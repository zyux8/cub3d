/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:24:45 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/23 16:10:48 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *str, char c)
{
	size_t	x;
	int		count;

	x = 0;
	count = 0;
	while (str[x])
	{
		while (str[x] == c)
			x++;
		if (str[x] != '\0')
			count++;
		while (str[x] && (str[x] != c))
			x++;
	}
	return (count);
}
/* Counts how many words are in the given string 'str', partet
	by the delimiter 'c'. */