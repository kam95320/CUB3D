/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:42:53 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/14 16:49:42 by kahoumou         ###   ########.fr       */
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

void	draw_vertical_line(t_cub *cub, int x)
{
	t_ray	*ray;
	int		y;
	int		color;
	int		lineheight;
	int		texture_x;
	int		texture_y;
	void	*texture_img;
	int		texture_color;

	ray = cub->ray;
	lineheight = ray->raylength;
	y = ray->startp;
	texture_x = (int)(ray->perpwalldist * 64) % 64;
	if (ray->whichside == 0)
	{
		if (ray->ray.x < 0)
			texture_img = cub->txt[WE]->img;
		else
			texture_img = cub->txt[EA]->img;
		color = 0xFF0000;
	}
	else if (ray->whichside == 1)
	{
		if (ray->ray.y < 0)
			texture_img = cub->txt[NO]->img;
		else
			texture_img = cub->txt[SO]->img;
		color = 0x00FF00;
	}
	if (texture_img != NULL)
	{
		texture_y = (int)((y - ray->startp) * 64 / lineheight);
		texture_color = get_texture_pixel(texture_img, texture_x, texture_y);
		mlx_pixel_put(cub->mlx, cub->win, x, y, texture_color);
	}
	else
	{
		while (y < ray->endp)
		{
			mlx_pixel_put(cub->mlx, cub->win, x, y, color);
			y++;
		}
	}
}
