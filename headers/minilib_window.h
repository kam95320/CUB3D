/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_window.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:46:24 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/17 15:36:21 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIB_WINDOW_H
# define MINILIB_WINDOW_H

// # include "raycasting.h"
# include "image.h"
# include "map.h"
# include "minimap.h"
# include "player.h"
# include "structure.h"
// # define WD_SIZE_WIDTH 640
// # define WD_SIZE_HEIGHT 480
// #define WD_SIZE_WIDTH 3840
// #define WD_SIZE_HEIGHT 2160

# define TILE_SIZE 34
typedef struct s_ray t_ray;

typedef struct s_minilib_window
{
	void			*mlx_connex;
	void			*window;
	int				size_weight;
	int				size_width;
	// char **mini_map;  maybe
	int				**text;
	t_map			map_data;
	t_player		player_info;
	t_ray			*ray;
	t_minimap		mn_mp;
	t_manip_img		mini_map;
	t_info_texture	*txt[4];
	t_cub			cub;
	t_manip_img		img;

	t_minimap		minimap_info;

}					t_minilib_window;

#endif