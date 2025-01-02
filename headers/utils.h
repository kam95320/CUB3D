/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:24:00 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/02 17:21:58 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../include/libft/libft.h"
# include "../include/minilibx-linux/mlx.h"
# include "image.h"
# include "minilib_window.h"
# include "player.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
void	print_error(char *str);
void	check_arg_init_mlx(int argc, char *argv[], t_minilib_window *mlx_data);
void	data_initializ(t_minilib_window *mlx_data);
void	mlx_initializ(t_minilib_window *mlx_data);
void	player_data_initialization(t_player *data_player);
void texture_data_initialization(t_info_texture *data_texture);

#endif // UTILS_H