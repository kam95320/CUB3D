/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setblock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:48:06 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/26 16:34:05 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	setblock(t_minilib_window *cub, int x, int y, int color)
{
	int xblock;
	int yblock;
	int save_x;
	int save_y;
	int zoom;

	zoom = cub->map_data.zoom / 4;
	yblock = cub->map_data.height / 2 + (y * zoom);
	save_y = yblock;
	while (--yblock > save_y - (2 * y * zoom))
	{
		xblock = cub->map_data.width / 2 + (x * zoom);
		save_x = xblock;
		while (--xblock > save_x - (2 * x * zoom))
			setpixel(cub->map_data, xblock, yblock, color, &cub->map_data);
	}
}