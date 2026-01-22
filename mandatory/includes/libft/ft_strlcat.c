/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:55:58 by ohaker            #+#    #+#             */
/*   Updated: 2025/11/21 22:59:59 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	x;
	size_t	max_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	max_len = dest_len + src_len;
	if (dest_len >= n)
		return (src_len + n);
	x = 0;
	while (src[x] && (dest_len + x) < (n - 1))
	{
		dest[dest_len + x] = src[x];
		x++;
	}
	dest[dest_len + x] = '\0';
	return (max_len);
}
/* Returns the length of the theoretical string when
	src is put at the end of dest */
