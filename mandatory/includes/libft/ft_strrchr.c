/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:58:03 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/14 22:25:12 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	x;

	x = ft_strlen(str);
	while (x >= 0)
	{
		if (str[x] == (char)c)
			return ((char *)(str + x));
		x--;
	}
	return (0);
}
/* Points to the last occurance of the character "c" */