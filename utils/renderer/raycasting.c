/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:51:37 by tespandj          #+#    #+#             */
/*   Updated: 2025/03/27 19:21:31 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	raycast(t_cub *cub)
{
	cub->ray->x = -1;
	while (++cub->ray->x < cub->data->width)
	{
		dda(cub, cub->ray);
		verticaline(cub, cub->ray, cub->ray->x);
	}
	mlx_put_image_to_window(cub->data->mlx, cub->data->win, cub->data->img, 0,
		0);
}

int	wallhit(t_cub *cub, double x, double y)
{
	if ((x < 0 || x > cub->map->l - 1) || (y < 0 || y > cub->map->L))
		return (1);
	if (cub->map->matrix[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

void	setpixel(t_data *data, int x, int y, int color)
{
	char *dst;
	if ((x < data->width && x >= 0) && (y < data->height && y >= 0))
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
	else
		printf("Bouffon t'ecris en dehors\n");
}