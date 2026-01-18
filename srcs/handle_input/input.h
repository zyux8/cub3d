/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 21:57:19 by ohaker            #+#    #+#             */
/*   Updated: 2026/01/19 00:20:24 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

//check_map_utils2 done
int			ft_isconfig(char *line);
int			ft_is_empty_or_whitespace(char *line);
t_playerpos	*init_player(int x, int y, int dir);
void		free_paths(char *p_no, char *p_so, char *p_we, char *p_ea);

//extract_map done
void		assign_pos(int *c, char sig);
int			get_player_pos(t_data *data);
int			is_map_char(char c);
void		copy_col(char *line, int *row, int width);
int			extract_map(t_data *data, char **lines);

//check_map_utils
int			valid_none(t_map *map, int x, int y);
void		malloc_map(int ***map, int height, int width);
int			count_lines(const char *filename);
char		**malloc_lines(const char *filename);
int			start_of_map(char **lines);

//extract_texts_utils
int			valid_colors(char **rgb);
int			get_color(char **lines, char *sig);
char		*get_single_text_path(char **lines, char *sig);
t_img		*get_texture(t_data *data, char *path);
int			is_texture(char **lines, char *sig);

//extract_texts
int			extract_floor(t_data *data, char **lines);
int			extract_ceiling(t_data *data, char **lines);
int			extract_bonus(t_data *data, char **lines);
int			extract_colors(t_data *data, char **lines);
int			extract_textures(t_data *data, char **lines);

//check_map
void		init_map(t_data *data);
int			get_height(char **lines, int start);
int			get_width(char **lines, int start);
int			map_valid(t_data *data);
int			check_map(int ac, char **av, t_data *data);

// validate_map
int			check_rows(t_map *map);
int			check_cols(t_map *map);
int			check_player(t_map *map);
int			check_nones(t_map *map);
int			check_door(t_data *data);

#endif