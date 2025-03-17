/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:27:00 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/17 13:46:48 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_WORLD_H
# define DRAW_WORLD_H

# include "utils.h"

typedef struct s_minilib_window	t_minilib_window;

// void draw_map_with_textures(t_minilib_window *mlx_data);
// void draw_wall_texture_a(t_minilib_window *mlx_data, int screen_x,
// int screen_y);
// void draw_map(t_minilib_window *mlx_data);
// void draw_wall_texture(t_minilib_window *mlx_data, int x);
// void map_create(t_minilib_window *data);
void							map_create(t_minilib_window *data, char **map);
void							render_map(t_minilib_window *data, char **map);
void							render_ceiling(t_minilib_window *data);
void							draw_square(t_minilib_window *data, int x,
									int y, int color);
void							render_floor(t_minilib_window *data);

#endif