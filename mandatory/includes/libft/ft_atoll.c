/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:22:55 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/02 20:27:39 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	int			x;
	int			neg;
	long long	res;

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
