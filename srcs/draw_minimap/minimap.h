/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:08:15 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/22 22:18:20 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "structs.h"

# define MINIMAP_SIZE 1000
# define TILE_SIZE 28
# define MINIMAP_W 200
# define MINIMAP_HEIGHT 200
# define MOVE_SPEED 0.12
# define ROT_SPEED 0.1
# define PI 3.141592653589793238462643383279502881971

// srcs/draw_minimap/draw_minimap.c
void	init_minimap(t_data *data);
void	draw_player(t_data *data);
void	draw_minimap(t_data *data);

// srcs/draw_minimap/minimap_utils.c
void	draw_frame(t_minimap *minimap);
int		player_close_to_door(t_data *data);

#endif