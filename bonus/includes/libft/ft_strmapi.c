/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:33:18 by ohaker            #+#    #+#             */
/*   Updated: 2025/11/21 19:04:01 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	x;
	char	*nstr;

	x = 0;
	nstr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!nstr)
		return (NULL);
	while (str[x])
	{
		nstr[x] = f(x, str[x]);
		x++;
	}
	nstr[x] = '\0';
	return (nstr);
}
/* Applies the given function 'f' on each character of the string 'str'
	and returns a new string of the modified characters. */