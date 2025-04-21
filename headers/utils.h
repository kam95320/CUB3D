/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:24:00 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/21 18:20:29 by kahoumou         ###   ########.fr       */
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
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define LIGHT_BLUE "\033[38;5;117m"
# define BG_BLUE "\033[44m"
# define FADED_BLUE "\033[38;5;250m"
# define CYAN "\033[36m"
# define SOFT_CYAN "\033[38;5;159m"
# define CYAN_FADE "\033[38;5;250m"
# define BG_SOFT_CYAN "\033[48;5;159m"
# define RESET "\033[0m"
# define PURPLE "\033[35m"
# define MINT_GREEN "\033[38;5;100m"
# define LIGHT_PURPLE "\033[95m"
# define SOFT_GREEN "\033[38;5;108m"
# define TEAL_GREEN "\033[38;5;37m"
# define RICH_PURPLE "\033[38;5;135m"
# define MUTED_PURPLE "\033[38;5;97m"

typedef struct s_minilib_window	t_minilib_window;
typedef struct s_cub			t_cub;
typedef struct s_ray			t_ray;
typedef struct s_cam			t_cam;
typedef struct s_data			t_data;
typedef struct s_map_data		t_map_data;
typedef struct spt				t_split;
typedef struct s_txt			t_txt;
typedef struct s_player			t_player;

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
void							fccolors(t_cub *cub, char *line, char ltr);
int								floor_or_ceiling(char lt, t_info_texture *txt);
bool							vrb_txt_valid(t_cub *cub);
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
void							caminit(t_cub *cub);
void							datainit(t_cub *cub);
void							fill_textures(t_cub *cub, char *line,
									char *verif);
void							fill_ceiling(t_cub *cub, char *line);
// void							fill_textures(t_cub *cub, char *line);
char							*verif_direct(char *line);
bool							textures(t_cub *cub, char *line);
void							fill_floor(t_cub *cub, char *line);
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
void							debug_txt(t_cub *cub);
void							floor_dg_col(t_cub *cub);
void							ceiling_debug_col(t_cub *cub);
void							all_debug(t_cub *cub);
void							color_init(t_cub *cub);
void							debug_raycasting(t_ray *ray);
void							debug_player(t_player *player);
char							*txt_cond(char **mp, int i, int j);
void							init_player(t_cub *cub);
bool							get_player_pos(t_cub *cub);
void							player_base(t_cub *cub);
bool							dir_is_find(t_cub *cub, char dir);
void							orig_pl_pos(t_cub *cub);
void							cast_single_ray(t_cub *cub, int x);
int								get_texture_pixel(void *img, int x, int y);
void							draw_vertical_line(t_cub *cub, int x);
void							raycast(t_cub *cub);
int								ray_loop(t_cub *cub);
void							key_init(t_cub *cub);
int								key_press(int code, t_cub *cub);
void							w_key(t_cub *cub);
void							s_key(t_cub *cub);
void							a_key(t_cub *cub);
void							d_key(t_cub *cub);
void							action_key(t_cub *cub);
void							rotate_left(t_cub *cub);
void							rotate_right(t_cub *cub);
void							rotate_right(t_cub *cub);
void							draw_cl_and_fl(t_cub *cub, t_ray *ray, int x);
void							single_ray_debug(t_cub *cub, int x);
void							debug_draw_cl_and_fl(t_cub *cub, t_ray *ray,
									int x);
void							debug_draw_cl_and_fl(t_cub *cub, t_ray *ray,
									int x);
void							debg_ray_calc(t_cub *cub, int x);
void							key_player(t_cub *cub);
void							move_straight(t_cub *cub);
void							init_player_dir_cam(t_cub *cub);
void							init_n_s(t_cub *cub, double pl_lenght);
void							init_e_w(t_cub *cub, double pl_lenght);
void							init_player_dir_cam(t_cub *cub);
void							print_ray_loop(t_cub *cub);

#endif // UTILS_H
