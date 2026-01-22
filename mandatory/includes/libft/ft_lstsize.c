/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:51:41 by ohaker            #+#    #+#             */
/*   Updated: 2024/11/23 16:16:47 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	x;

	x = 0;
	while (lst)
	{
		x++;
		lst = lst->next;
	}
	return (x);
}
/* Counts the number of nodes in a list. */