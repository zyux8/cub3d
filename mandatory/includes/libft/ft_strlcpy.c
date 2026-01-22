/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:45:03 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/13 21:45:14 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str);

int	ft_strlcpy(char *dest, const char *src, unsigned long n)
{
	unsigned int	x;

	if (n == 0)
		return (ft_strlen(src));
	x = 0;
	while (x < (n - 1) && src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (ft_strlen(src));
}
/* Copys the string from src to dest to a given position */