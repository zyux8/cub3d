/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:20:20 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/18 16:25:36 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	x;
	size_t	y;
	char	*strout;

	x = 0;
	y = ft_strlen(str);
	strout = (char *)malloc((y + 1) * sizeof(char));
	if (!strout)
		return (NULL);
	while (y > 0)
	{
		strout[x] = str[y - 1];
		x++;
		y--;
	}
	strout[x] = '\0';
	return (strout);
}
/* This reverses the given string and returns it. */

// int	main(void)
// {
// 	char	*str = "reverse this";

// 	printf("%s", ft_strrev(str));
// 	return (0);
// }
