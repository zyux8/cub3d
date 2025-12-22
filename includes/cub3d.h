/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:05:36 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/22 22:16:35 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../srcs/frees/free.h"
# include "../srcs/handle_input/input.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "../srcs/draw_minimap/minimap.h"
# include "structs.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

// srcs/input_handler.c
void	update_player_pos(t_data *data);
void	move_player(t_data *data, double move_x, double move_y);
int		handle_destroy(t_data *data);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);

// srcs/main.c
void	init_data(t_data *data);
void	cleanup_and_exit(t_data *data);

// srcs/utils.c
void	my_pixel_put(t_img *img, int x, int y, int color);
int		create_rgb(int r, int g, int b);
t_keys	*init_key_struct(void);

#endif