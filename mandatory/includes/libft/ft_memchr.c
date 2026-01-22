/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:25:29 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/19 14:53:10 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const void	*ft_memchr(const void *str, int c, unsigned long n)
{
	unsigned int	x;
	unsigned char	*pstr;

	x = 0;
	pstr = (unsigned char *)str;
	while (x < n)
	{
		if (pstr[x] == (unsigned char)c)
			return (pstr + x);
		x++;
	}
	return (0);
}
/* Searches the input string, to position 'n',
	for the first occurance of the character and returns
	a pointer to that character. */