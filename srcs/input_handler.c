/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:42:31 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/01 21:52:02 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_key(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		cleanup_and_exit(data);
	// else if (keycode == KEY_UP)
	// 	something up
	// else if (keycode == KEY_DOWN)
	// 	something down
	// else if (keycode == KEY_RIGHT)
	// 	something right
	// else if (keycode == KEY_LEFT)
	// 	something left
	return (0);
}

int	handle_destroy(t_data *data)
{
	cleanup_and_exit(data);
	return (0);
}
