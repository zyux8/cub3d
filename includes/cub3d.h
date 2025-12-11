/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:05:36 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/11 18:16:53 by ohaker           ###   ########.fr       */
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

typedef struct s_map	t_map;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	char				*addr;
	void				*img;
	int					bits_per_pixel;
	int					line_len;
	int					endian;
	t_map				*map;
}						t_data;

enum					e_map_info
{
	GROUND = 0,
	WALL,
	NONE,
	PLAYER_N,
	PLAYER_E,
	PLAYER_S,
	PLAYER_W,
};

typedef struct s_texture
{
	void				*img_ptr;
	char				*addr;
	int					width;
	int					height;
	int					bits_per_pixel;
	int					line_len;
	int					endian;
}						t_texture;

typedef struct s_map
{
	t_texture			*tex_north;
	t_texture			*tex_south;
	t_texture			*tex_west;
	t_texture			*tex_east;
	t_texture			*tex_floor;
	t_texture			*tex_ceiling;
	int					ceiling_color;
	int					floor_color;
	int					**map;
	int					map_height;
	int					map_width;
	// int				player_pos[2];
	enum e_map_info		player_facing;
}						t_map;

// srcs/extract_map/check_map_even_more.c
char					*get_single_text_path(char **lines, char *sig);
void					malloc_map(int ***map, int height, int width);
int						get_color(char **lines, char *sig);

// srcs/extract_map/check_map_utils_more.c
void					init_map(t_data *data);
int						start_of_map(char **lines);
void					copy_col(char *line, int *row, int width);
int						get_height(char **lines, int start);
int						get_width(char **lines, int start);

// srcs/extract_map/check_map_utils.c
int						count_lines(const char *filename);
char					**malloc_lines(const char *filename);
int						create_rgb(int r, int g, int b);
void					free_paths(char *p_no, char *p_so, char *p_we,
							char *p_ea);
int						is_map_char(char c);

// srcs/extract_map/check_map.c
int						check_map(char *file, t_data *data);

// srcs/extract_map/validate_map.c
int						map_valid(t_data *data);

// srcs/input_handler.c
int						handle_key(int keycode, t_data *data);
int						handle_destroy(t_data *data);

// srcs/main.c
void					cleanup_and_exit(t_data *data);

// srcs/utils.c
void					my_pixel_put(t_data *data, int x, int y, int color);

#endif