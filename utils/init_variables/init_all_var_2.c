/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_var_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:45:59 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/17 17:02:43 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	datainit(t_cub *cub)
{
	printf("\n----datainit deb----\n");
	cub->data->width = 660;
	cub->data->height = 600;
	cub->data->mlx = mlx_init();
	printf("before  get  screen cub->data->width = %d\n", cub->data->width);
	printf("before  get  screen cub->data->height = %d\n", cub->data->height);
	mlx_get_screen_size(cub->data->mlx, &cub->data->width, &cub->data->height);
	printf("after  get  screen cub->data->width = %d\n", cub->data->width);
	printf("after  get  screen cub->data->height = %d\n", cub->data->height);
	cub->data->win = mlx_new_window(cub->data->mlx, cub->data->width,
			cub->data->height, "CUB3D");
	
	if (!cub->data->win)
	{
		free(cub->data->mlx);
		wgas(cub, "Couldn't open the window", NULL);
	}
	cub->data->img = mlx_new_image(cub->data->mlx, cub->data->width,
			cub->data->height);
	cub->data->addr = mlx_get_data_addr(cub->data->img,
			&cub->data->bits_per_pixel, &cub->data->line_length,
			&cub->data->endian);
	printf("\n----datainit end----\n");
}

void	ciminit(t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	while (cub->map->matrix[++y])
	{
		x = -1;
		while (cub->map->matrix[y][++x])
		{
			if (cub->map->matrix[y][x] == 'N' || cub->map->matrix[y][x] == 'S'
				|| cub->map->matrix[y][x] == 'E'
				|| cub->map->matrix[y][x] == 'O')
			{
				cub->map->matrix[y][x] = '0';
				cub->cam->player_pos = (t_mgam2f){x + 0.5, y + 0.5};
				break ;
			}
		}
	}
	cub->cam->look = (t_mgam2f){1.0, 0.0};
	mlx_mouse_move(cub->data->mlx, cub->data->win, cub->data->width / 2,
		cub->data->height / 2);
	mlx_mouse_get_pos(cub->data->mlx, cub->data->win, &cub->cam->mouse_x,
		&cub->cam->mouse_y);
}
void	rayinit(t_ray *ray)
{
	ray->x = 0;
	ray->map = (t_mgam2i){0, 0};
	ray->step = (t_mgam2i){-1, -1};
	ray->ray = (t_mgam2f){0.0, 0.0};
	ray->plane = (t_mgam2f){0.0, 0.66};
	ray->sidedist = (t_mgam2f){0.0, 0.0};
	ray->deltadist = (t_mgam2f){0.0, 0.0};
	ray->camerax = 0.0;
	ray->perpwalldist = 0.0;
	ray->whichside = 0;
}