/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_window.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:46:24 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/02 15:44:59 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "image.h"
# include "minimap.h"
# include "player.h"
# include "raycasting.h"
# define WD_SIZE_WIDTH 640
# define WD_WIN_HEIGHT 480
typedef struct s_minilib_window
{
	void			*mlx_connex;
	void			*window;
	int				size_weight;
	int				size_width;
	// char **mini_map;  maybe;
	int				**pix_mem_texture;
	int				**text;
	t_player		player_info;
	t_raycasting	raycating_info;
	t_info_texture	texture_info;
	t_minimap		minimap_info;

}					t_minilib_window;

#endif