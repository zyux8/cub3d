/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:15:41 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/14 18:20:50 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, unsigned long n)
{
	unsigned int		x;
	unsigned char		*pdest;
	const unsigned char	*psrc;

	x = 0;
	psrc = src;
	pdest = dest;
	if (pdest == 0 && psrc == 0)
		return (0);
	while (x < n)
	{
		pdest[x] = psrc[x];
		x++;
	}
	return (pdest);
}
/* Copys the a given amount of the given string to the given destination */