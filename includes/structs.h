/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:06:01 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/22 22:17:13 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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

#endif