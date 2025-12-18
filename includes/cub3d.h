/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:05:36 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/18 17:09:51 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
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
# define MINIMAP_SIZE 1000
# define TILE_SIZE 26
# define MINIMAP_W 200
# define MINIMAP_H 200
# define MOVE_SPEED 0.12
# define ROT_SPEED 0.1
# define PI 3.141592653589793238462643383279502881971

typedef struct s_map		t_map;
typedef struct s_playerpos	t_playerpos;
typedef struct s_keys		t_keys;
typedef struct s_minimap	t_minimap;

typedef struct s_img
{
	void					*img;
	char					*addr;
	int						width;
	int						height;
	int						bits_per_pixel;
	int						line_len;
	int						endian;
}							t_img;

typedef struct s_data
{
	void					*mlx;
	void					*win;
	t_img					*view;
	t_map					*map;
	t_minimap				*minimap;
	t_playerpos				*player;
	t_keys					*keys;
}							t_data;

enum						e_map_info
{
	GROUND = 0,
	WALL,
	NONE,
	PLAYER_N,
	PLAYER_E,
	PLAYER_S,
	PLAYER_W,
	DOOR,
	SPRITE,
};

typedef struct s_playerpos
{
	double					x_pos;
	double					y_pos;
	double					facing;
}							t_playerpos;

typedef struct s_keys
{
	int						key_up;
	int						key_do;
	int						key_ri;
	int						key_le;
}							t_keys;

typedef struct s_map
{
	t_img					*tex_north;
	t_img					*tex_south;
	t_img					*tex_west;
	t_img					*tex_east;
	t_img					*tex_floor;
	t_img					*tex_ceiling;
	t_img					*tex_door;
	t_img					*tex_sprite;
	int						ceiling_color;
	int						floor_color;
	int						**map;
	int						map_height;
	int						map_width;
	enum e_map_info			player_facing;
}							t_map;

typedef struct s_minimap
{
	t_img					*img;
	double					x_off;
	double					y_off;
}							t_minimap;

void						print_map(t_data *data);

// srcs/draw_minimap/draw_minimap.c
void						init_minimap(t_data *data);
void						draw_player(t_data *data);
void						draw_minimap(t_data *data);

// srcs/draw_minimap/minimap_utils.c
void						draw_frame(t_minimap *minimap);

// srcs/handle_input/check_map_even_more.c
char						*get_single_text_path(char **lines, char *sig);
void						malloc_map(int ***map, int height, int width);
int							get_color(char **lines, char *sig);
int							get_player_pos(t_data *data);

// srcs/handle_input/check_map_utils_more.c
void						init_map(t_data *data);
int							start_of_map(char **lines);
void						copy_col(char *line, int *row, int width);
int							get_height(char **lines, int start);
int							get_width(char **lines, int start);

// srcs/handle_input/check_map_utils.c
int							count_lines(const char *filename);
char						**malloc_lines(const char *filename);
void						free_paths(char *p_no, char *p_so, char *p_we,
								char *p_ea);
int							is_map_char(char c);
t_img						*get_texture(t_data *data, char *path);

// srcs/handle_input/check_map.c
int							check_rows(t_map *map);
int							check_cols(t_map *map);
int							check_player(t_map *map);
int							check_nones(t_map *map);
int							check_map(char *filename, t_data *data);

// srcs/handle_input/extract_texts.c
int							extract_colors(t_data *data, char **lines);

// srcs/handle_input/more_more_more_utils.c
void						copy_col(char *line, int *row, int width);

// srcs/handle_input/validate_map.c
int							map_valid(t_map *map);

// srcs/input_handler.c
void						update_player_pos(t_data *data);
void						move_player(t_data *data, double move_x,
								double move_y);
int							handle_destroy(t_data *data);
int							key_press(int keycode, t_data *data);
int							key_release(int keycode, t_data *data);

// srcs/main.c
void						cleanup_and_exit(t_data *data);

// srcs/utils.c
void						my_pixel_put(t_img *img, int x, int y, int color);
int							create_rgb(int r, int g, int b);
t_keys						*init_key_struct(void);

#endif