/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:01:16 by ohaker            #+#    #+#             */
/*   Updated: 2025/11/06 15:05:34 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *s)
{
	int	x;
	int	len;

	x = 0;
	len = ft_strlen(s);
	while (s[x] && ft_isdigit(s[x]))
		x++;
	if (x == len)
		return (1);
	return (0);
}

// checks a string is its whole numeric.