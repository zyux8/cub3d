/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbarthol <pbarthol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:43:24 by pbarthol          #+#    #+#             */
/*   Updated: 2026/01/14 16:08:19 by pbarthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYCAST_H
# define CUB3D_RAYCAST_H

# define FOV 70

// srcs/raycasting/cub3d_raycast_main.c
unsigned int	c3_rycst_shade(unsigned int color, float dist);
void			draw_line(t_data *data, int pixel_col, float dist);
void			c3_rycst_main(t_data *data);

#endif
