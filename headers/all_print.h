/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_print.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:42:44 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/25 20:25:05 by kahoumou         ###   ########.fr       */
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
typedef struct s_manip_img		t_manip_img;
typedef struct s_player			t_player;
typedef struct s_minimap		t_minimap;
typedef struct two_d_s			two_d_t;
void							all_print_info(t_minilib_window mlx_data,
									two_d_t two_d, t_player *player,
									char **map);
void							print_texture_info(t_info_texture *texture);
void							print_data_strcut(t_minilib_window *data,
									char *map);
void							print_minilib_window_info(t_minilib_window *window);
void							print_map_info(t_map *map);
void							print_two_d_info(two_d_t *two_d);
void							print_player_info(t_player *player);
void							print_manip_img_info(t_manip_img *img);
void							size_is_valide(t_manip_img *img,
									t_minilib_window *data);
void							test_put_img(t_minilib_window *mlx_data);
void							draw_map(t_minilib_window *mlx_data);
void							draw_wall_texture(t_minilib_window *mlx_data,
									int x);

void							draw_wall_texture_a(t_minilib_window *mlx_data,
									int screen_x, int screen_y);
#endif // ALL_PRINT_H
