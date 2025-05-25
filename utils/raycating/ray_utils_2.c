/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:34:42 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/24 19:05:11 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	get_texture_pixel(void *img, int x, int y)
{
	char	*texture_data;
	int		bpp;
	int		size_line;
	int		endian;
	int		color;

	texture_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	color = *(int *)(texture_data + (y * size_line + x * (bpp / 8)));
	return (color);
}

void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	calc_wall_hit(t_ray *ray, t_player *pl)
{
	if (ray->whichside == 0)
		return (pl->fl_pl_pos_y + ray->perpwalldist * ray->ray.y
			- floor(pl->fl_pl_pos_y + ray->perpwalldist * ray->ray.y));
	else
		return (pl->fl_pl_pos_x + ray->perpwalldist * ray->ray.x
			- floor(pl->fl_pl_pos_x + ray->perpwalldist * ray->ray.x));
}

void	*get_texture(t_cub *cub)
{
	t_ray	*ray;

	ray = cub->ray;
	if (ray->whichside == 0)
	{
		if (ray->ray.x < 0)
			return (cub->txt[WE]->img);
		else
			return (cub->txt[EA]->img);
	}
	else
	{
		if (ray->ray.y < 0)
			return (cub->txt[NO]->img);
		else
			return (cub->txt[SO]->img);
	}
}

int	is_walkable_cell(t_cub *cub, double x, double y)
{
	int map_x;
	int map_y;

	map_x = (int)x;
	map_y = (int)y;

	if (map_x < 0 || map_y < 0)
		return (0);
	if (map_y >= cub->data->height)
		return (0);
	if (map_x >= (int)ft_strlen(cub->map->matrix[map_y]))
		return (0);
	if (cub->map->matrix[map_y][map_x] != '0')
		return (0);
	return (1);
}
