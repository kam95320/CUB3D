/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:49:03 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/27 15:41:51 by kahoumou         ###   ########.fr       */
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