/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbarthol <pbarthol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:43:24 by pbarthol          #+#    #+#             */
/*   Updated: 2026/01/21 16:30:10 by pbarthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYCAST_H
# define CUB3D_RAYCAST_H

/* Field of view in degrees for the player's perspective */
# define FOV 70
/* Minimum brightness factor to prevent complete darkness at distance */
# define MAX_SHADING 0.5

/* ************************************************************************** */
/*                  cub3d_raycast_main.c - INITIALIZATION & MAIN LOOP         */
/* ************************************************************************** */

/* Allocates and initializes the per-frame raycasting state */
t_raycast		*init_raycast(void);
/* Per-column raycasting loop: casts and steps ray until wall hit */
void			c3_rycst_main_loop(t_data *data, int i);
/* Main raycasting loop that casts rays for the entire view */
void			c3_rycst_main(t_data *data);

/* ************************************************************************** */
/*              cub3d_raycast_utils.c - GRID STEPPING                         */
/* ************************************************************************** */

/* Calculates initial step direction and starting distances for both axes */
void			c3_rycst_initial_dist(t_data *data);
/* Advances the ray one grid cell and reports wall hits */
void			c3_rycst_grid_step(t_data *data, int i);

/* ************************************************************************** */
/*              cub3d_raycast_draw.c - DRAWING & SHADING                      */
/* ************************************************************************** */

/* Draws one vertical column for ceiling, floor, or textured wall pixels */
void			c3_rycst_draw_line_loop(t_data *data, int pixel_col, int start,
					int line_height);
/* Calculates wall projection height and delegates pixel painting */
void			c3_rycst_draw_line(t_data *data, int pixel_col);
/* Applies distance-based shading to a color value */
unsigned int	c3_rycst_shade(unsigned int color, float dist);

/* ************************************************************************** */
/*             cub3d_raycast_texturing.c - TEXTURING & SAMPLING               */
/* ************************************************************************** */

/* Selects the wall texture based on ray impact side and direction */
t_img			*c3_rycst_assign_text(t_data *data);
/* Computes the normalized wall coordinate where the ray hits */
float			c3_rycst_find_text_pixel_util(t_data *data);
/* Samples the wall texture at the hit point and applies shading */
unsigned int	c3_rycst_find_text_pixel(t_data *data, float i);

#endif
