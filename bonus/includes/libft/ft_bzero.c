/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:38:21 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/13 12:28:36 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_bzero(void *s, unsigned long c)
{
	unsigned int	x;
	unsigned char	*ptrs;

	x = 0;
	ptrs = (unsigned char *)s;
	while (x != c)
	{
		ptrs[x] = 0;
		x++;
	}
	return (s);
}
/* Replaces every character up to a certain position with '0' */