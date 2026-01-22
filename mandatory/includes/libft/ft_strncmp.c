/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:14:46 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/15 17:01:18 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	x;

	x = 0;
	if (n == 0)
		return (0);
	while (x < n - 1 && str1[x] && str1[x] == str2[x])
		x++;
	return ((unsigned char)str1[x] - (unsigned char)str2[x]);
}
/* Compares two strings to a certain position and has output:
• 0, if the s1 and s2 are equal;

• a negative value if s1 is less than s2;

• a positive value if s1 is greater than s2.*/