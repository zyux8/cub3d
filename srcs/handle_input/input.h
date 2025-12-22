/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 21:57:19 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/22 22:17:10 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "structs.h"

// srcs/handle_input/check_map_even_more.c
char	*get_single_text_path(char **lines, char *sig);
void	malloc_map(int ***map, int height, int width);
int		get_color(char **lines, char *sig);
int		get_player_pos(t_data *data);

// srcs/handle_input/check_map_utils_more.c
void	init_map(t_data *data);
int		start_of_map(char **lines);
void	copy_col(char *line, int *row, int width);
int		get_height(char **lines, int start);
int		get_width(char **lines, int start);

// srcs/handle_input/check_map_utils.c
int		count_lines(const char *filename);
char	**malloc_lines(const char *filename);
void	free_paths(char *p_no, char *p_so, char *p_we, char *p_ea);
int		is_map_char(char c);
t_img	*get_texture(t_data *data, char *path);

// srcs/handle_input/check_map.c
int		check_rows(t_map *map);
int		check_cols(t_map *map);
int		check_player(t_map *map);
int		check_nones(t_map *map);
int		check_map(int ac, char **av, t_data *data);

// srcs/handle_input/extract_texts.c
int		extract_colors(t_data *data, char **lines);

// srcs/handle_input/more_more_more_utils.c
void	copy_col(char *line, int *row, int width);

// srcs/handle_input/validate_map.c
int		map_valid(t_map *map);

#endif