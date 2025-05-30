/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:49:03 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/24 18:25:14 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../include/libft/libft.h"
# include "../include/minilibx-linux/mlx.h"
# include "free.h"
# include "image.h"
# include "minilib_window.h"
# include "player.h"
# include "two_d.h"
# include "utils.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MMAP 16
# define MAP_VOID 0x353831
// # define MAP_WALL 0x090C08
# define MAP_WALL 0xFF0000
# define MAP_PLAYER 0x474056

# define MAP_SKY 0x778BF0
# define MAP_FLOOR 0x7C7C7C

# define NO 0
# define SO 1
# define EA 2
# define WE 3

# define MOVESPEED 0.02
# define ROTATESPEED 0.02

typedef struct s_mgam2f
{
	double						x;
	double						y;
}								t_mgam2f;

typedef struct s_mgam2i
{
	int							x;
	int							y;
}								t_mgam2i;

// struct t_minilib_window;
typedef struct s_minilib_window	t_minilib_window;

typedef struct s_cam
{
	t_mgam2f					player_pos;
	t_mgam2f					look;
	int							mouse_x;
	int							mouse_y;
}								t_cam;
typedef struct s_txt
{
	void						*img;
	void						*addr;
	char						*name;
	int							width;
	int							height;
	int							bits_per_pixel;
	int							size_line;
	int							endian;
}								t_txt;

typedef struct s_ray
{
	t_mgam2i					map;
	t_mgam2f					ray;
	t_mgam2f					plane;
	t_mgam2f					sidedist;
	t_mgam2f					deltadist;
	t_mgam2i					step;
	double						camerax;
	double						perpwalldist;
	double						wall_x;
	int							x;
	int							raylength;
	int							whichside;
	int							startp;
	int							endp;
	int							hit;
}								t_ray;

#endif //  RAYCASTING_H