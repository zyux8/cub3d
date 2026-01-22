/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:35:39 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/19 14:55:00 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned long	x;
	unsigned char	*pstr1;
	unsigned char	*pstr2;

	x = 0;
	pstr1 = (unsigned char *)str1;
	pstr2 = (unsigned char *)str2;
	while (n > x)
	{
		if (pstr1[x] != pstr2[x])
			return (pstr1[x] - pstr2[x]);
		x++;
	}
	return (0);
}
/* Returns a negative, positive or NULL value dependant of
	the string parts that are being compared. */