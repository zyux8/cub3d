/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:40:51 by ohaker            #+#    #+#             */
/*   Updated: 2025/11/08 20:41:03 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, long unsigned int amount_of_chars)
{
	char	*str;
	size_t	x;

	x = 0;
	str = (char *)malloc((amount_of_chars + 1) * sizeof(*s));
	if (!str)
		return (NULL);
	while (s[x] && x < amount_of_chars)
	{
		str[x] = s[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}
