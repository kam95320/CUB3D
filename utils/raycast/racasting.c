/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   racasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:00:54 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/27 12:45:12 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	raycast(t_minilib_window *data)
{
	printf("pass in raycast deb size_weight =  %d\n", data->size_weight);
	printf("pass in raycast deb size_weight =  %d\n\n", data->size_width);
	int	y;
	int	x;
		y = -1;
	// reset_cub(cub);
	while (++y < data->size_weight)
	{
		// printf("pass in raycast while y =  %d\n", y);
		x = -1;
		while (++x < data->size_width)
		{
			// printf("pass in raycast while x = %d\n", x);
			setpixel(data, x, y, 0x8895B3, &data->map_data);
		}
		printf("pass in raycast while y exit =  %d\n", y);
	}
	// printf("pass in raycast while x exit =  %d\n", x);
	aff_map(data);
	aff_cam(data);
	printf("pass in raycast end\n");
}
