/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_print.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:42:44 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/03 15:49:15 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_PRINT_H
# define ALL_PRINT_H

# include "../include/libft/libft.h"
# include "../include/minilibx-linux/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_info_texture	t_info_texture;
typedef struct s_minilib_window	t_minilib_window;
typedef struct s_map			t_map;

void							print_texture_info(t_info_texture *texture);
void							print_data_strcut(t_minilib_window *data,
									char *map);
void							print_minilib_window_info(t_minilib_window *window);
void							print_map_info(t_map *map);
void							print_two_d_info(two_d_t *two_d);
void							print_player_info(t_player *player);
void							print_manip_img_info(t_manip_img *img);
#endif // ALL_PRINT_H
