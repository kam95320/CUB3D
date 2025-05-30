/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:28:37 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/30 19:02:15 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	ray_loop(t_cub *cub)
{
	int			x;
	static int	frame = 0;

	x = -1;
	if (frame == 0)
	{
		mlx_destroy_image(cub->data->mlx, cub->data->img);
		frame = 1;
	}
	cub->data->img = mlx_new_image(cub->data->mlx, cub->data->width,
			cub->data->height);
	cub->data->addr = mlx_get_data_addr(cub->data->img,
			&cub->data->bits_per_pixel, &cub->data->line_length,
			&cub->data->endian);
	while (++x < cub->data->width)
	{
		// printf("x = %d || widht = %d\n", x,cub->data->width);
		// cast_single_ray(cub, x);
		// draw_cl_and_fl(cub, cub->ray, x);
		// draw_vertical_line(cub, x, cub->ray, cub->player);
		printf("[RAY %d/%d]\n", x, cub->data->width);
		cast_single_ray(cub, x);
		printf("cast_single_ray ok x=%d\n", x);
		draw_cl_and_fl(cub, cub->ray, x);
		printf("draw_cl_and_fl ok x=%d\n", x);
		draw_vertical_line(cub, x, cub->ray, cub->player);
		printf("draw_vertical_line ok x=%d\n", x);
	}
	printf("FIN RAY LOOP\n");
	debg_ray_calc(cub, x);
	mlx_put_image_to_window(cub->data->mlx, cub->data->win, cub->data->img, 0,
		0);
	key_player(cub);
	mlx_destroy_image(cub->data->mlx, cub->data->img);
	return (0);
}
