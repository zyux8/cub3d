/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:15:44 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/19 14:35:14 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c);

int	ft_atoi(const char *str)
{
	int	x;
	int	neg;
	int	res;

	x = 0;
	neg = 1;
	res = 0;
	while (str[x] == ' ' || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '-')
	{
		neg = -1;
		x++;
	}
	else if (str[x] == '+')
		x++;
	while (ft_isdigit(str[x]))
	{
		res = (res * 10) + (str[x] - '0');
		x++;
	}
	return (res * neg);
}
/* Converts a portion of the input given string into int. */