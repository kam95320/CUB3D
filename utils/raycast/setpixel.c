/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:18:21 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/26 16:30:22 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../headers/utils.h"

// typedef struct s_map
// {
// 	char	*path;
// 	char	**file;
// 	int		fd;
// 	int		line_len;
// 	int		height;
// 	int		width;
// 	int		map_ending;

// }			t_map;


void	setpixel(t_minilib_window *data, int x, int y, int color, t_map  *map)
{
	char	*dst;

	if ((x < data->size_width && x > 0) && (y < data->size_weight && y > 0))
	{
		dst = data->img.pix_img + (y * map->line_len + x
				* data->img.pix_img);
		*(unsigned int*)dst = color;
	}
}