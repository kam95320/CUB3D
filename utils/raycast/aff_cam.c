/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:39:39 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/26 16:54:00 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"


// typedef struct s_minilib_window
// {
// 	void			*mlx_connex;
// 	void			*window;
// 	int				size_weight;
// 	int				size_width;
// 	// char **mini_map;  maybe
// 	int				**pix_mem_texture;
// 	int				**text;
// 	t_map			map_data;
// 	t_player		player_info;
// 	t_raycasting	raycating_info;
// 	t_info_texture	texture_info;
// 	t_manip_img		img;
// 	t_minimap		minimap_info;

// }					t_minilib_window;

void	aff_cam(t_minilib_window *cub)
{
	int	xz;
	int	yz;

	yz = cub->ray.y + cub->map_data.zoom / 2;
	while (--yz > cub->ray.y - cub->map_data.zoom / 2)
	{
		xz = cub->ray.x + cub->map_data.zoom / 2;
		while (--xz > cub->ray.x - cub->map_data.zoom / 2)
			setpixel(cub, xz, yz, 255, &cub->map_data);
	}
}
