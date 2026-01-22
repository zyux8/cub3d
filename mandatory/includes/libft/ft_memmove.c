/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:55:15 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/14 16:59:09 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace(char *pdest, const char *psrc, unsigned long n)
{
	int	x;

	if (pdest > psrc)
	{
		x = (int)n - 1;
		while (x >= 0)
		{
			pdest[x] = psrc[x];
			x--;
		}
	}
	else
	{
		x = 0;
		while (x < (int)n)
		{
			pdest[x] = psrc[x];
			x++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, unsigned long n)
{
	char		*pdest;
	const char	*psrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	pdest = (char *)dest;
	psrc = (const char *)src;
	ft_replace(pdest, psrc, n);
	return (dest);
}
/* Copys the a given amount of the given string to the given destination
	and replaces the copied characters from the string with '\0' */