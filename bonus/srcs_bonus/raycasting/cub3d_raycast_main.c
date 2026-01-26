/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:42:20 by pbarthol          #+#    #+#             */
/*   Updated: 2026/01/26 14:20:01 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/**
 * Allocates and initializes the per-frame raycasting state.
 * Fields are set to neutral defaults so callers can immediately update them
 * for each cast ray.
 *
 * @return pointer to a cleared raycast state, or NULL on allocation failure
 */
t_raycast	*init_raycast(void)
{
	t_raycast	*raycast;

	raycast = malloc(sizeof(t_raycast));
	if (!raycast)
		return (NULL);
	raycast->ray_angle = 0;
	raycast->ray_dir_x = 0;
	raycast->ray_dir_y = 0;
	raycast->initial_x = 0;
	raycast->initial_y = 0;
	raycast->delta_dist_x = 0;
	raycast->delta_dist_y = 0;
	raycast->dist_x = 0;
	raycast->dist_y = 0;
	raycast->dist = 0;
	raycast->step_x = 0;
	raycast->step_y = 0;
	raycast->hit_vertical = 0;
	raycast->map_tile = 0;
	return (raycast);
}

/**
 * Per-column raycasting: initializes ray position and distances, then steps
 * through grid cells until a blocking wall or closed door is encountered.
 * When a wall is hit, the column is drawn and the loop terminates.
 *
 * @param data - main game state containing map, player, and render targets
 * @param i    - screen column index for the current ray
 */
void	c3_rycst_main_loop(t_data *data, int i)
{
	data->raycast->ray_pos_x = data->player->x_pos;
	data->raycast->ray_pos_y = data->player->y_pos;
	data->raycast->dist_x = data->raycast->delta_dist_x
		* data->raycast->initial_x;
	data->raycast->dist_y = data->raycast->delta_dist_y
		* data->raycast->initial_y;
	while (1)
	{
		c3_rycst_grid_step(data, i);
		data->raycast->map_tile = data->map->map[data->raycast->ray_pos_y]
		[data->raycast->ray_pos_x];
		if (data->raycast->map_tile == WALL || (data->raycast->map_tile == DOOR
				&& !player_close_to_door(data)))
		{
			c3_rycst_draw_line(data, i);
			break ;
		}
	}
}

/**
 * Main raycasting loop: emits one ray per screen column, advances through the
 * grid until a wall or closed door is hit, then draws the projected slice.
 *
 * @param data - main game state containing map, player, and render targets
 */
void	c3_rycst_main(t_data *data)
{
	int		i;

	i = -1;
	if (data->view && data->view->addr)
		ft_bzero(data->view->addr, (size_t)data->view->line_len
			* (size_t)data->view->height);
	while (++i < WIN_WIDTH)
		c3_rycst_main_loop(data, i);
}
