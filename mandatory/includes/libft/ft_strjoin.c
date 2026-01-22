/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:15:22 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/02 20:21:51 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*str;
	size_t	tlen;
	size_t	x;
	size_t	y;

	if (!str1 && !str2)
		return (NULL);
	if (!str1)
		return (ft_strdup(str2));
	if (!str2)
		return (ft_strdup(str1));
	tlen = ft_strlen(str1) + ft_strlen(str2);
	str = (char *)malloc((tlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strcpy(str, str1);
	x = 0;
	y = ft_strlen(str1);
	while (str2[x])
		str[y++] = str2[x++];
	str[y] = '\0';
	return (str);
}
/* Returns a string which is str2 put at the end of str1. */