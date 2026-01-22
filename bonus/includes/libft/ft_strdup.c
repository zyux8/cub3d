/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:57:13 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/19 14:55:22 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	x;

	x = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(*s));
	if (!str)
		return (NULL);
	while (s[x])
	{
		str[x] = s[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}
/* Returns a pointer to a new string which is
	a duplicate of the input string 's'. */