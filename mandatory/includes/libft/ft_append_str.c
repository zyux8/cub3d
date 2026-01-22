/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:07:38 by ohaker            #+#    #+#             */
/*   Updated: 2025/11/18 00:11:04 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append_str(char *dest, char *src)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	if (src == NULL)
	{
		if (dest == NULL)
			return (NULL);
		return (ft_strdup(dest));
	}
	len1 = 0;
	if (dest != NULL)
		len1 = ft_strlen(dest);
	len2 = ft_strlen(src);
	new_str = malloc(len1 + len2 + 1);
	if (new_str == NULL)
		return (NULL);
	if (dest != NULL)
		ft_memcpy(new_str, dest, len1);
	ft_memcpy(new_str + len1, src, len2);
	new_str[len1 + len2] = '\0';
	return (new_str);
}
// appends the string src onto dest
