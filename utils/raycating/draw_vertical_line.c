/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:42:53 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/15 17:09:54 by kahoumou         ###   ########.fr       */
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

void	draw_vertical_line(t_cub *cub, int x)
{
	t_ray	*ray;
	int		y;
	int		lineheight;
	int		texture_x;
	int		texture_y;
	void	*texture_img;
	int		texture_color;

	ray = cub->ray;
	y = ray->startp;
	lineheight = ray->raylength;
	texture_x = (int)(ray->perpwalldist * 64) % 64;
	if (ray->whichside == 0)
	{
		if (ray->ray.x < 0)
			texture_img = cub->txt[WE]->img;
		else
			texture_img = cub->txt[EA]->img;
	}
	else
	{
		if (ray->ray.y < 0)
			texture_img = cub->txt[NO]->img;
		else
			texture_img = cub->txt[SO]->img;
	}
	while (y < ray->endp)
	{
		texture_y = (int)((y - ray->startp) * 64 / lineheight);
		texture_color = get_texture_pixel(texture_img, texture_x, texture_y);
		put_pixel(cub->data, x, y, texture_color);
		y++;
	}
}

void	draw_cl_and_fl(t_cub *cub, int x)
{
	t_ray	*ray;
	int		y;

	y = 0;
	while (y < ray->startp)
	{
		put_pixel(cub->data, x, y, cub->map->ceiling_cl_hx);
		y++;
	}
	while (y < cub->data->height)
	{
		put_pixel(cub->data, x, y, cub->map->floor_cl_hx);
		y++;
	}
}
