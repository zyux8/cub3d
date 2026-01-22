/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:10:42 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/23 16:24:07 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	size_t	x;

	x = 0;
	while (str[x])
	{
		f(x, &str[x]);
		x++;
	}
}
/* Iterates through the string 'str' and applies the given function
	on each character. */