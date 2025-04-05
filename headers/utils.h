/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:24:00 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/05 14:23:33 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../include/libft/libft.h"
# include "../include/minilibx-linux/mlx.h"
# include "all_print.h"
# include "draw_world.h"
# include "free.h"
# include "image.h"
# include "minilib_window.h"
# include "player.h"
# include "raycasting.h"
# include "structure.h"
# include "two_d.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PIXEL_SIZE 128
# define VIEW_DIST 4
# define COLOR_PLAYER 0xFF0000
# define COLOR_WALL 0x2E2E2E
# define COLOR_FLOOR 0xA0D6B4
# define COLOR_SPACE 0x1C1C1C

typedef struct s_minilib_window	t_minilib_window;
typedef struct s_cub			t_cub;
typedef struct s_ray			t_ray;
typedef struct s_cam			t_cam;
typedef struct s_data			t_data;
typedef struct s_map_data		t_map_data;
typedef struct spt				t_split;
typedef struct s_txt			t_txt;

void							print_error(char *str);
void							check_arg_init_mlx(int argc, char *argv[],
									t_cub *cub);
void							data_initializ(t_minilib_window *mlx_data);
void							mlx_initializ(t_minilib_window *mlx_data);
void							player_data_initialization(t_player *data_player);
void							texture_data_initialization(t_info_texture *data_texture);
bool							check_is_valid(char *file);
bool							check_open(char *file);
bool							check_is_cub_file(char *file);
bool							check_is_xpm_file(char *file);
bool							take_mem_map(t_cub *cub, two_d_t *two_d,
									char *mp);
void							completed_2d(two_d_t *two_d, t_cub *cub);
bool							map_is_valid(t_cub *cub);
int								nb_line(char *map);
int								skip_space(char **mp, int i, int len);
bool							is_good_print(t_cub *cub, char **mp, int i,
									int j);
int								manage_txt_space(char *stc, int len, int cond);
void							fccolors(t_cub *cub);
int								floor_or_ceiling(char lt, t_info_texture *txt);
bool							vrb_txt_valid( t_cub *cub);
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
void							get_map_size(t_map_data *map, char **file);
void							initialization_texture(t_manip_img *img,
									t_minilib_window *data);
void							restart_img(t_manip_img *img);

int								cub3d(t_cub *cub);
int								looping(t_cub *cub);
bool							is_line_empty(char *line);

void							rayinit(t_ray *ray);
void							convert_map_data(t_map_data *dest,
									t_minilib_window *win);
int								press(int key, t_cub *cub);
int								release(int key, t_cub *cub);
int								mousemotion(t_cub *cub);
void							movement(t_cub *cub);
int								end_win(t_cub *cub);
void							next_line(t_cub *cub, char **line);
void							wgas(t_cub *cub, char *arg, char *str);
void							wegotasplituation(struct spt x);
void							free_map(t_cub *cub);
void							freend(t_cub *cub);
int								null_line(char *str);
void							fsplit(char **str);
void							gnl_free(int fd);
char							*erase_new_line(char *str);

void							lookmove(t_ray *ray, t_cam *cam, int key);
int								wallhit(t_cub *cub, double x, double y);
void							setpixel(t_data *data, int x, int y, int color);
void							dda(t_cub *cub, t_ray *ray);
void							verticaline(t_cub *cub, t_ray *ray, int x);
void							bridge_of_struct(t_cub *cub,
									t_minilib_window *win);
void							raycast(t_cub *cub, t_ray *ray);
void							caminit(t_cub *cub);
void							datainit(t_cub *cub);
void							fill_textures(t_cub *cub, char *line,
									char *verif);
// void							fill_textures(t_cub *cub, char *line);
void							everyinit(t_cub *cub);
void							datainit(t_cub *cub);
void							ciminit(t_cub *cub);
void							rayinit(t_ray *ray);
void							txtinit(t_cub *cub);
int								tstrcmp(char *str, char *cmp);
char							*erase_new_line(char *str);
void							caminit(t_cub *cub);
void							init_textures(t_cub *cub);
void							texture_pixel(t_cub *cub, t_ray *ray);
void							fsplit(char **str);
void							free_textures(t_txt **txt);
#endif // UTILS_H
