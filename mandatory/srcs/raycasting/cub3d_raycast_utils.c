/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbarthol <pbarthol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:24:36 by pbarthol          #+#    #+#             */
/*   Updated: 2026/01/21 16:26:53 by pbarthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Moves the ray to the next grid boundary, tracks whether the hit was on a
 * vertical side, and triggers drawing when a wall or closed door is reached.
 *
 * @param data   - main game state containing ray data and map
 * @param i      - screen column index currently being processed
 * @return 0 when a blocking tile is hit (drawing performed), 1 to keep stepping
 */
void	c3_rycst_grid_step(t_data *data, int i)
{
	data->raycast->ray_angle = data->player->facing - (data->map->actual_fov
			/ 2) + i * (data->map->actual_fov / WIN_WIDTH);
	data->raycast->ray_dir_x = cos(data->raycast->ray_angle);
	data->raycast->ray_dir_y = sin(data->raycast->ray_angle);
	c3_rycst_initial_dist(data);
	data->raycast->delta_dist_x = fabs(1 / data->raycast->ray_dir_x);
	data->raycast->delta_dist_y = fabs(1 / data->raycast->ray_dir_y);
	if (data->raycast->dist_x <= data->raycast->dist_y)
	{
		data->raycast->dist = data->raycast->dist_x;
		data->raycast->ray_pos_x += data->raycast->step_x;
		data->raycast->dist_x += data->raycast->delta_dist_x;
		data->raycast->hit_vertical = 1;
	}
	else
	{
		data->raycast->dist = data->raycast->dist_y;
		data->raycast->ray_pos_y += data->raycast->step_y;
		data->raycast->dist_y += data->raycast->delta_dist_y;
		data->raycast->hit_vertical = 0;
	}
}

/**
 * Computes initial step direction and starting distances for both axes based
 * on the ray direction and the player's fractional position within the grid.
 *
 * @param data - main game state containing player position and ray data
 */
void	c3_rycst_initial_dist(t_data *data)
{
	if (data->raycast->ray_dir_x >= 0)
	{
		data->raycast->initial_x = fabs(data->player->x_pos - ceil(data->player
					->x_pos));
		data->raycast->step_x = 1;
	}
	if (data->raycast->ray_dir_x < 0)
	{
		data->raycast->initial_x = fabs(floor(data->player->x_pos) - data
				->player->x_pos);
		data->raycast->step_x = -1;
	}
	if (data->raycast->ray_dir_y >= 0)
	{
		data->raycast->initial_y = fabs(data->player->y_pos - ceil(data->player
					->y_pos));
		data->raycast->step_y = 1;
	}
	if (data->raycast->ray_dir_y < 0)
	{
		data->raycast->initial_y = fabs(floor(data->player->y_pos) - data
				->player->y_pos);
		data->raycast->step_y = -1;
	}
}
