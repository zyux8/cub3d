/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:06:01 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/22 22:14:50 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map		t_map;
typedef struct s_playerpos	t_playerpos;
typedef struct s_keys		t_keys;
typedef struct s_raycast	t_raycast;
typedef struct s_minimap	t_minimap;
typedef struct s_cigar		t_cigar;
typedef struct s_fps_count	t_fps_count;
typedef struct s_data		t_data;

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
	t_raycast				*raycast;
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
	int						key_w;
	int						key_a;
	int						key_s;
	int						key_d;
	int						key_sp;
}							t_keys;

typedef struct s_raycast
{
	float					ray_angle;
	float					ray_dir_x;
	float					ray_dir_y;
	float					initial_x;
	float					initial_y;
	float					delta_dist_x;
	float					delta_dist_y;
	float					dist_x;
	float					dist_y;
	float					dist;
	int						step_x;
	int						step_y;
	int						ray_pos_x;
	int						ray_pos_y;
	int						hit_vertical;
	int						map_tile;
}							t_raycast;


typedef struct s_map
{
	t_img					*tex_north;
	t_img					*tex_south;
	t_img					*tex_west;
	t_img					*tex_east;
	t_img					*tex_floor;
	int						ceiling_color;
	int						floor_color;
	int						**map;
	int						map_height;
	int						map_width;
	enum e_map_info			player_facing;
	float					actual_fov;
}							t_map;

#endif