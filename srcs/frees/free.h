/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:10:38 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/22 22:15:34 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "structs.h"

// srcs/frees/free_helpers.c
void	free_img(t_img *img, void *mlx);
void	free_minimap(t_minimap *mm, void *mlx);
void	free_player(t_playerpos *p);
void	free_keys(t_keys *k);
void	free_lines(char **lines);

// srcs/frees.free1.c
void	cleanup_and_exit(t_data *data);

#endif