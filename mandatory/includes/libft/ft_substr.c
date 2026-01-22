/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:23:18 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/19 14:54:35 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	x;
	size_t	y;
	size_t	s_len;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	s_len = ft_strlen(s + start);
	if (s_len < len)
		len = s_len;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	x = start;
	y = 0;
	while (s[x] && y < len)
	{
		str[y] = s[x];
		y++;
		x++;
	}
	str[y] = '\0';
	return (str);
}
/* Creates a new string which is a part of the input given string 's'
	and bordered by start and end. */