/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:36:10 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/19 14:54:16 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, unsigned long c);

void	*ft_calloc(size_t num, size_t size)
{
	void	*arr;

	arr = (void *)malloc(num * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, num * size);
	return (arr);
}
/* Allocates memory for an array of 'num' elements of 'size' bytes each
	and	returns a pointer to the allocated memory. */