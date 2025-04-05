/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:51:37 by tespandj          #+#    #+#             */
/*   Updated: 2025/04/04 10:55:38 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/raycasting.h"
#include "../../headers/structure.h"
#include "../../headers/utils.h"

// static t_txt	*cardinalstxt(t_cub *cub)
// {
// 	if (cub->ray->whichside)
// 	{
// 		if (cub->ray->ray.y > 0)
// 			return (cub->txt[EA]);
// 		return (cub->txt[WE]);
// 	}
// 	if (cub->ray->ray.x > 0)
// 		return (cub->txt[NO]);
// 	return (cub->txt[SO]);
// }
// void	texture_pixel_2(t_cub *cub, t_ray *ray)
// {
// 	int		length;
// 	int		color = 0;
// 	int		pas;
// 	t_txt	*dir;

// 	dir = cardinalstxt(cub);
// 	ray->startp = ray->startp - 1;
// 	if (ray->startp < 0)
// 		ray->startp = 0;
// 	length = ray->raylength;

// 	pas = 1 * dir->height / length;
// 	dir->addr = mlx_get_data_addr(
// 		dir->img,
// 		&dir->bits_per_pixel,
// 		&dir->size_line,
// 		&dir->endian
// 	);

// 	while (++ray->startp < ray->endp)
// 		setpixel(cub->data, cub->ray->x, ray->startp, color);

// 	(void)pas; // tu l’utiliseras sûrement plus tard pour accéder à la texture
// }

void	raycast(t_cub *cub, t_ray *ray)
{
	int	y;

	y = -1;
	printf("\n-----raycast deb------\n");
	printf("-----raycast deb------\n");
	printf("ray->x = %d\n", ray->x);
	printf("ray->dir_x = %d\n", ray->x);
	if (ray->x < 0 || ray->x >= cub->data->width)
	{
		printf("❌ ray->x = %d dépasse cub->data->width = %d\n", ray->x,
			cub->data->width);
		return ;
	}
	ray->startp = -ray->raylength / 2 + cub->data->height / 2;
	if (ray->startp < 0)
		ray->startp = 0;
	ray->endp = ray->raylength / 2 + cub->data->height / 2;
	if (ray->endp >= cub->data->height)
		ray->endp = cub->data->height - 1;
	while (++y < ray->startp)
	{
		// printf("ray->dir_y = %d\n", y);
		// printf("ray->startp  = %d\n", ray->startp );
		setpixel(cub->data, cub->ray->x, y, MAP_SKY);
	}
	texture_pixel(cub, cub->ray);
	y = ray->endp - 1;
	while (++y < cub->data->height)
		setpixel(cub->data, cub->ray->x, y, MAP_FLOOR);
	printf("\n-----raycast end------\n");
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
	char	*dst;

	if ((x < data->width && x >= 0) && (y < data->height && y >= 0))
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
	else
		printf("Bouffon t'ecris en dehors\n");
}
