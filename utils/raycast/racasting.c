/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   racasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:00:54 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/26 16:33:34 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	raycast(t_minilib_window *data)
{
	int	y;
	int	x;

	y = -1;
	// reset_cub(cub);
	while (++y < data->size_weight)
	{
		x = -1;
		while (++x < data->size_width)
			setpixel(data, x, y, 0x8895B3, &data->map_data);
	}
	aff_map(data);
	aff_cam(data);
}
