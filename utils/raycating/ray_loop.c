/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:28:37 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/15 17:10:23 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	ray_loop(t_cub *cub)
{
	int x;
	x = -1;
	cub->data->img = mlx_new_image(cub->data->mlx, cub->data->width,
			cub->data->height);
	cub->data->addr = mlx_get_data_addr(cub->data->img, &cub->data->addr,
			&cub->data->line_length, &cub->data->endian);

	while (++x < cub->data->width)
	{
		cast_single_ray(cub, x);
		draw_vertical_line(cub, x);
		draw_cl_and_fl(cub, x);
	}
	mlx_put_image_to_window(cub->data->mlx, cub->data->win, cub->data->img, 0,
		0);
	mlx_destroy_image(cub->data->mlx, cub->data->img);
}