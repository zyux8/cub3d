/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:27:46 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/23 16:11:07 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int n)
{
	int	x;

	x = 0;
	if (n <= 0)
		x++;
	while (n)
	{
		n /= 10;
		x++;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	int		x;
	long	temp;
	char	*str;

	temp = n;
	x = ft_count(temp);
	str = (char *)malloc((x + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[x] = '\0';
	if (temp < 0)
	{
		str[0] = '-';
		temp *= -1;
	}
	x--;
	while (temp >= 10)
	{
		str[x] = (temp % 10) + '0';
		temp /= 10;
		x--;
	}
	str[x] = temp + 48;
	return (str);
}
/* Converts an integer into ascii value. */