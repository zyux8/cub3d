/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:11:07 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/19 14:53:45 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	y;
	size_t	z;

	x = 0;
	if (little[x] == '\0')
		return ((char *)big);
	while (big[x] != '\0' && x < len)
	{
		y = 0;
		z = x;
		while (little[y] == big[x + y] && z < len)
		{
			if (little[y + 1] == '\0')
				return ((char *)&big[x]);
			z++;
			y++;
		}
		x++;
	}
	return (NULL);
}
/* Returns a pointer to the first character of the string
	little in the string big, when the string little is inside
	the set limiter 'len'. */