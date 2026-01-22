/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:26:38 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/13 12:28:51 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, unsigned long n)
{
	unsigned int	x;
	unsigned char	*ptrs;

	x = 0;
	ptrs = (unsigned char *)s;
	while (x != n)
	{
		ptrs[x] = (unsigned char)c;
		x++;
	}
	return (s);
}
/* Replaces every character up to position n with given int c */