/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:55:03 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/23 16:22:09 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	size_t	x;

	x = 0;
	while (str[x])
	{
		ft_putchar(str[x]);
		x++;
	}
}
/* Outputs the string 'str' as standard output. */