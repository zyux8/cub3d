/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:08:15 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/26 14:18:02 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MINIMAP_H
# define DRAW_MINIMAP_H
# include "structs.h"

# define TILE_SIZE 28
# define MINIMAP_W 200
# define MINIMAP_H 200

// srcs/draw_minimap/draw_minimap.c
void	init_minimap(t_data *data);
void	draw_player(t_data *data);
void	draw_square(t_data *data, int x_pos, int y_pos, int block);
void	draw_minimap(t_data *data);

// srcs/draw_minimap/draw_minimap_utils.c
void	draw_frame(t_minimap *minimap);
int		player_close_to_door(t_data *data);
void	draw_fov(t_data *data);

#endif