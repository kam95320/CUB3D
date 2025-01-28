/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:24:00 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/28 14:00:06 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../include/libft/libft.h"
# include "../include/minilibx-linux/mlx.h"
# include "image.h"
# include "minilib_window.h"
# include "player.h"
# include "two_d.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
void	print_error(char *str);
void	check_arg_init_mlx(int argc, char *argv[], t_minilib_window *mlx_data);
void	data_initializ(t_minilib_window *mlx_data);
void	mlx_initializ(t_minilib_window *mlx_data);
void	player_data_initialization(t_player *data_player);
void	texture_data_initialization(t_info_texture *data_texture);
bool	check_is_valid(char *file);
bool	check_open(char *file);
bool	check_is_cub_file(char *file);
bool	check_is_xpm_file(char *file);
bool	take_mem_map(t_minilib_window *mlx_data, two_d_t *two_d, char *mp);
void	completed_2d(two_d_t *two_d, t_minilib_window *data);
bool	map_is_valid(char **mp, t_minilib_window *data_mlx);
int		nb_line(char *map);
int		skip_space(char **mp, int i, int len);
bool	is_good_print(t_info_texture *txt, char **mp, int i, int j);
int		manage_txt_space(char *stc, int len, int cond);
bool	color(t_info_texture *txt, char *mp, int j, int F_C);
int		floor_or_ceiling(char *lt, t_info_texture *txt);
bool	vrb_txt_valid(t_info_texture *txt);
int		hx_txt(t_info_texture *txt, char lt);
#endif // UTILS_H