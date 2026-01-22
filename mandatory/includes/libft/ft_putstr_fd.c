/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:30:51 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/23 16:21:48 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	size_t	x;

	x = 0;
	while (str[x])
	{
		ft_putchar_fd(str[x], fd);
		x++;
	}
}
/* Outputs the string 'str' to the given file descriptor. */