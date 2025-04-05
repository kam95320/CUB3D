/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridge_of_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:09:56 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/02 17:23:44 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

// void bridge_of_structure(t_map_data *dest, t_minilib_window *win)
// {
// 	convert_map_data(dest, win);
// }

// void convert_map_data(t_map_data *dest, t_minilib_window *win)
// {
// 	dest->matrix = win->map_data.file;
// 	dest->L = win->map_data.height;
// 	dest->l = win->map_data.width;
// 	dest->NO = win->texture_info.direct_north;
// 	dest->SO = win->texture_info.direct_south;
// 	dest->WE = win->texture_info.direct_west;
// 	dest->EA = win->texture_info.direct_east;

// 	dest->floor = malloc(sizeof(t_rgb));
// 	dest->floor->r = win->texture_info.floor[0];
// 	dest->floor->g = win->texture_info.floor[1];
// 	dest->floor->b = win->texture_info.floor[2];

// 	dest->ceiling = malloc(sizeof(t_rgb));
// 	dest->ceiling->r = win->texture_info.ceiling[0];
// 	dest->ceiling->g = win->texture_info.ceiling[1];
// 	dest->ceiling->b = win->texture_info.ceiling[2];
// }

// void	convert_map_data(t_map_data *dest, t_minilib_window *win)
// {
// 	dest->matrix = win->map_data.file;
// 	dest->L = win->map_data.height;
// 	dest->l = win->map_data.width;
// 	dest->floor = malloc(sizeof(t_rgb));
// 	if (!dest->floor)
// 		return ;
// 	dest->floor->r = win->texture_info.floor[0];
// 	dest->floor->g = win->texture_info.floor[1];
// 	dest->floor->b = win->texture_info.floor[2];
// 	dest->ceiling = malloc(sizeof(t_rgb));
// 	if (!dest->ceiling)
// 	{
// 		free(dest->floor);
// 		return ;
// 	}
// 	dest->ceiling->r = win->texture_info.ceiling[0];
// 	dest->ceiling->g = win->texture_info.ceiling[1];
// 	dest->ceiling->b = win->texture_info.ceiling[2];
// }

// void	convert_data(t_data *dest, t_minilib_window *win)
// {
// 	dest->mlx = win->mlx_connex;
// 	dest->win = win->window;
// 	dest->img = win->img.ptr_img;
// 	dest->addr = (char *)win->img.pixel_img;
// 	dest->width = win->size_width;
// 	dest->height = win->size_weight;
// 	dest->endian = win->img.oct_indian;
// 	dest->bits_per_pixel = win->img.pix_img;
// 	dest->line_length = win->img.size_of_line;
// 	dest->x_off = 0;
// 	dest->y_off = 0;
// }

// void	convert_cam(t_cam *dest, t_minilib_window *win)
// {
// 	dest->player_pos.x = win->player_info.player_pos_x;
// 	dest->player_pos.y = win->player_info.player_pos_y;
// 	dest->look.x = win->player_info.look_x;
// 	dest->look.y = win->player_info.look_y;
// 	dest->mouse_x = win->player_info.mouse_x;
// 	dest->mouse_y = win->player_info.mouse_y;
// }
// void	convert_cam(t_cam *dest, t_minilib_window *win)
// {
// 	dest->player_pos.x = win->player_info.fl_pl_pos_x;
// 	dest->player_pos.y = win->player_info.fl_pl_pos_y;
// 	dest->look.x = win->player_info.cam_pos_x;
// 	dest->look.y = win->player_info.cam_pos_y;
// 	dest->mouse_x = win->player_info.gesture_x;
// 	dest->mouse_y = win->player_info.gesture_y;
// }
// void	init_keys(t_keys *keys)
// {
// 	keys->w = 0;
// 	keys->a = 0;
// 	keys->s = 0;
// 	keys->d = 0;
// 	keys->l = 0;
// 	keys->r = 0;
// 	keys->q = 0;
// }

// void	convert_textures(t_txt *dest, t_manip_img *src)
// {
// 	dest->img = src->ptr_img;
// 	dest->addr = (void *)src->pixel_img;
// 	dest->width = src->size_of_line;
// 	dest->height = 0;
// 	dest->bits_per_pixel = src->pix_img;
// 	dest->size_line = src->size_of_line;
// 	dest->endian = src->oct_indian;
// 	dest->name = NULL;
// }

// void	convert_textures(t_txt *txt, void *mlx, char *path)
// {
// 	printf("===> Loading texture: %s\n", path);
// 	txt->img = mlx_xpm_file_to_image(mlx, path, &txt->width, &txt->height);
// 	if (!txt->img)
// 	{
// 		fprintf(stderr, "❌ mlx_xpm_file_to_image failed: %s\n", path);
// 		return ;
// 	}
// 	txt->addr = mlx_get_data_addr(txt->img, &txt->bits_per_pixel, &txt->size_line, &txt->endian);
// 	if (!txt->addr)
// 	{
// 		fprintf(stderr, "❌ mlx_get_data_addr failed: %s\n", path);
// 		return ;
// 	}
// 	printf("✅ Texture loaded: %s\n", path);
// }

// void	bridge_of_struct(t_cub *cub, t_minilib_window *win)
// {
// 	cub->map = malloc(sizeof(t_map_data));
// 	cub->data = malloc(sizeof(t_data));
// 	cub->cam = malloc(sizeof(t_cam));
// 	cub->ray = malloc(sizeof(t_ray));
// 	// cub->txt = malloc(sizeof(t_txt) * 4);
// 	// if (!cub->txt)
// 	// {
// 	// 	fprintf(stderr, "[❌] Échec malloc cub->txt\n");
// 	// 	exit(1);
// 	// }
// 	convert_map_data(cub->map, win);
// 	convert_data(cub->data, win);
// 	convert_cam(cub->cam, win);
// 	init_keys(&cub->keys);
// }
