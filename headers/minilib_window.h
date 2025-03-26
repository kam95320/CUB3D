/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_window.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:46:24 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/26 16:35:45 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIB_WINDOW_H
# define MINILIB_WINDOW_H

# include "image.h"
# include "map.h"
# include "minimap.h"
# include "player.h"
# include "raycasting.h"
# include "structure.h"
// # define WD_SIZE_WIDTH 640
// # define WD_SIZE_HEIGHT 480
# define WD_SIZE_WIDTH 1280
# define WD_SIZE_HEIGHT 720
// #define WD_SIZE_WIDTH 3840
// #define WD_SIZE_HEIGHT 2160

# define TILE_SIZE 34

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
	t_ray			ray;
	t_minimap		mn_mp;
	t_manip_img		mini_map;
	t_info_texture	texture_info;
	t_cub			cub;
	t_manip_img		img;

	t_minimap		minimap_info;

}					t_minilib_window;

#endif