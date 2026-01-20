/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbarthol <pbarthol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:43:24 by pbarthol          #+#    #+#             */
/*   Updated: 2026/01/20 18:28:57 by pbarthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYCAST_H
# define CUB3D_RAYCAST_H

/* Field of view in degrees for the player's perspective */
# define FOV 70
/* Minimum brightness factor to prevent complete darkness at distance */
# define MAX_SHADING 0.25

/* ************************************************************************** */
/*                     RAYCASTING CORE FUNCTIONS                              */
/* ************************************************************************** */

/* Applies distance-based shading to a color value */
unsigned int	c3_rycst_shade(unsigned int color, float dist);
/* Renders a vertical wall slice at the given screen column */
void			c3_rycst_draw_line(t_data *data, int pixel_col);
/* Allocates and initializes the per-frame raycasting state */
t_raycast		*init_raycast(void);
/* Main raycasting loop that casts rays for the entire view */
void			c3_rycst_main(t_data *data);

/* ************************************************************************** */
/*                     TEXTURE SAMPLING FUNCTIONS                             */
/* ************************************************************************** */

/* Selects the wall texture based on ray impact side and direction */
t_img			*c3_rycst_assign_text(t_data *data);
/* Computes the normalized wall coordinate where the ray hits */
float			c3_rycst_find_text_pixel_util(t_data *data);
/* Samples the wall texture at the hit point and applies shading */
unsigned int	c3_rycst_find_text_pixel(t_data *data, float i);

#endif
