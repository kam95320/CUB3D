/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:28:37 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/18 10:30:13 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

// static void	print_ray_loop(t_cub *cub)
// {
// 	printf(" ray_loop -> cub->data->mlx =  %p\n", cub->data->mlx);
// 	printf(" ray_loop -> cub->data->width =  %d\n", cub->data->width);
// 	printf("ray_loop -> cub->data->height=  %d\n", cub->data->height);
// }
int	ray_loop(t_cub *cub)
{
	// printf("\n-----ray_loop deb-----\n");
	int x;
	x = -1;
	// print_ray_loop(cub);
	cub->data->img = mlx_new_image(cub->data->mlx, cub->data->width,
			cub->data->height);
	// printf("\n----in ray_loop-----\n");
	cub->data->addr = mlx_get_data_addr(cub->data->img,
			&cub->data->bits_per_pixel, &cub->data->line_length,
			&cub->data->endian);
	while (++x < cub->data->width)
	{
		//  printf(RED "x = %d | wight = %d\n" RESET, x, cub->data->width);
		cast_single_ray(cub, x);
		// printf(GREEN "pass cast_single_ray\n"RESET);
		draw_cl_and_fl(cub, cub->ray, x);
		draw_vertical_line(cub, x);
		// printf(GREEN "pass draw_vertical_line\n"RESET);
		// printf(GREEN "pass draw_cl_and_fl\n" RESET);
		 debg_ray_calc(cub, x);
	}
	mlx_put_image_to_window(cub->data->mlx, cub->data->win, cub->data->img, 0,
		0);
	action_key(cub);
	mlx_destroy_image(cub->data->mlx, cub->data->img);
	// printf("\n-----ray_loop end-----\n");
	return (0);
}