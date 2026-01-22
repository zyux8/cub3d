/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:05:36 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/22 21:51:14 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../srcs_bonus/draw_minimap/draw_minimap.h"
# include "../srcs_bonus/frees/free.h"
# include "../srcs_bonus/handle_input/input.h"
# include "../srcs_bonus/raycasting/cub3d_raycast.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
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
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_SP 32
# define KEY_Z 122
# define MOUSE_SENSITIVITY 0.0005
# define MOVE_SPEED 0.12
# define ROT_SPEED 0.07
# define PI 3.1415926535897932384626433832795028841971

// srcs/input_handler.c
int			handle_destroy(t_data *data);
int			key_press(int keycode, t_data *data);
int			key_release(int keycode, t_data *data);
int			mouse_move(int x, int y, t_data *data);

// srcs/main.c
void		init_data(t_data *data);
void		cleanup_and_exit(t_data *data);

// srcs/utils.c
void		my_pixel_put(t_img *img, int x, int y, int color);
int			create_rgb(int r, int g, int b);
t_keys		*init_key_struct(void);
void		update_player_pos(t_data *data);
void		move_player(t_data *data, double move_x, double move_y);

// overlay/overlay_cigar.c
t_cigar		*init_cigar(t_data *data);
int			get_pixel_color(t_img *img, int x, int y);
void		overlay_image(t_img *dest, t_img *src, int x_off, int y_off);
int			load_cigar(t_data *data);

// overlay/overlay_cigar.c
void		loop_smoke(t_data *data);
int			init_smoke(t_data *data, t_cigar *cigar);

t_fps_count	*init_fps_count(void);
void		c3_fps_count(t_data *data);
void		update_player_movement(t_data *data, float speed);

#endif