/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:49:03 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/26 17:32:03 by kahoumou         ###   ########.fr       */
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


# define M_PI 3.14159265358979323846
# define SPACE 64
# define RATIO_PLAYER 8
# define RATIO_MOVE 4

# define MAP_VOID 0x353831
// # define MAP_WALL 0x090C08
# define MAP_WALL 0xFF0000
# define MAP_PLAYER 0x474056

# define MAP_SKY 0x778BF0
# define MAP_FLOOR 0x7C7C7C

# define MOVESPEED 0.02
# define ROTATESPEED 0.02

typedef double	t_mgam2f __attribute__((ext_vector_type(2)));
typedef int		t_mgam2i __attribute__((ext_vector_type(2)));


// struct t_minilib_window;
typedef struct s_minilib_window	t_minilib_window;

typedef struct s_cam
{
	t_mgam2f	player_pos;
	t_mgam2f	look;
	int		mouse_x;
	int		mouse_y;
}		t_cam;

typedef struct s_ray
{
	t_mgam2i	map;
	t_mgam2f	ray;
	t_mgam2f	plane;
	t_mgam2f	sidedist;
	t_mgam2f	deltadist;
	t_mgam2i	step;
	double		camerax;
	double		perpwalldist;
	int			x;
	int			raylength;
	int			whichside;
	int			startp;
	int			endp;
}		t_ray;


#endif //  RAYCASTING_H