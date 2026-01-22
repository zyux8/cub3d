/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:36:43 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/23 16:21:13 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
			ft_putnbr(n);
		}
		else if (n < 10)
		{
			c = n + '0';
			ft_putchar(c);
		}
		else
		{
			ft_putnbr(n / 10);
			c = (n % 10) + '0';
			ft_putchar(c);
		}
	}
}
/* Outputs the interger 'n' as standard output. */