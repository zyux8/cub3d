/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:04:56 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/21 15:18:16 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chrnbr(char *str, char c)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (str[x])
	{
		if (str[x] == c)
			y++;
		x++;
	}
	return (y);
}
/* Counts how often the character 'c' appears in the string 'str'. */

// int	main(void)
// {
// 	char	*str = "stringstring ss";

// 	printf("%d", ft_chrnbr(str, 's'));
// 	return (0);
// }
