/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:24:00 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/13 18:42:38 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../include/libft/libft.h"
# include "../include/minilibx-linux/mlx.h"
# include "all_print.h"
# include "free.h"
# include "image.h"
# include "minilib_window.h"
# include "player.h"
# include "raycasting.h"
# include "two_d.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include "draw_world.h"
# define PIXEL_SIZE 128
# define VIEW_DIST 4
# define COLOR_PLAYER 0xFF0000 // Rouge vif (Joueur)
# define COLOR_WALL 0x2E2E2E   // Gris foncé (Murs)
# define COLOR_FLOOR 0xA0D6B4  // Vert pâle (Sol)
# define COLOR_SPACE 0x1C1C1C  // Noir/gris foncé (Espaces vides)

typedef struct s_minilib_window	t_minilib_window;

void							print_error(char *str);
void							check_arg_init_mlx(int argc, char *argv[],
									t_minilib_window *mlx_data);
void							data_initializ(t_minilib_window *mlx_data);
void							mlx_initializ(t_minilib_window *mlx_data);
void							player_data_initialization(t_player *data_player);
void							texture_data_initialization(t_info_texture *data_texture);
bool							check_is_valid(char *file);
bool							check_open(char *file);
bool							check_is_cub_file(char *file);
bool							check_is_xpm_file(char *file);
bool							take_mem_map(t_minilib_window *mlx_data,
									two_d_t *two_d, char *mp);
void							completed_2d(two_d_t *two_d,
									t_minilib_window *data);
bool							map_is_valid(char **mp,
									t_minilib_window *data_mlx);
int								nb_line(char *map);
int								skip_space(char **mp, int i, int len);
bool							is_good_print(t_info_texture *txt, char **mp,
									int i, int j);
int								manage_txt_space(char *stc, int len, int cond);
bool							color(t_info_texture *txt, char *mp, char ltr);
int								floor_or_ceiling(char lt, t_info_texture *txt);
bool							vrb_txt_valid(t_info_texture *txt);
void							hx_txt(t_info_texture *txt, char lt, int *rgb);
void							init_var_pl_e_w(t_player *player);
void							init_var_pl_n_s(t_player *player);
void							initialzation_mlx(t_minilib_window *data);
int								*texture_convert(t_minilib_window *data,
									char *txt_ph);
void							init_direct(t_minilib_window *mlx_data);
void							init_img_txt_textures(t_minilib_window *mlx_data);
void							initialzation_txt(t_minilib_window *data,
									t_manip_img *m_img, char *txt_ph);
void							mlx_exit(t_minilib_window *data);
void							all_free(t_minilib_window *data);
void							get_map_size(t_map *map, char **file);
void							initialization_texture(t_manip_img *img,
									t_minilib_window *data);

void							restart_img(t_manip_img *img);

// void	raycast(t_minilib_window *data);
// void	setpixel(t_minilib_window *data, int x, int y, int color, t_map *map);
// void	aff_map(t_minilib_window *cub);
// void	setblock(t_minilib_window *cub, int x, int y, int color);

#endif // UTILS_H