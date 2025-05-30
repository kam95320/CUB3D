/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:42:53 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/30 19:15:29 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"
static int get_texture_dir(t_ray *ray)
{
	// whichside == 0 -> mur vertical (Est/Ouest), regarde ray->ray.x
	// whichside == 1 -> mur horizontal (Nord/Sud), regarde ray->ray.y
	if (ray->whichside == 0)
	{
		if (ray->ray.x > 0)
			return (EA); // Est
		else
			return (WE); // Ouest
	}
	else
	{
		if (ray->ray.y > 0)
			return (SO); // Sud
		else
			return (NO); // Nord
	}
}
void	draw_vertical_line(t_cub *cub, int x, t_ray *ray, t_player *pl)
{
	void	*texture_img;
	int		texture_x;
	int		texture_y;
	int		texture_color;
	int		y;
	int		height;
	int		width;
	int		d;

	height = cub->txt[get_texture_dir(ray)]->height;
	width = cub->txt[get_texture_dir(ray)]->width;
	texture_img = get_texture(cub);
	if (ray->whichside == 0)
		ray->wall_x = pl->fl_pl_pos_y + ray->perpwalldist * ray->ray.y;
	else
		ray->wall_x = pl->fl_pl_pos_x + ray->perpwalldist * ray->ray.x;
	ray->wall_x -= floor(ray->wall_x);
	texture_x = (int)(ray->wall_x * (double)width);
	if ((ray->whichside == 0 && ray->ray.x > 0) || (ray->whichside == 1
			&& ray->ray.y < 0))
		texture_x = width - texture_x - 1;
	y = ray->startp;
	while (y < ray->endp)
	{
		d = y * 256 - cub->data->height * 128 + ray->raylength * 128;
		texture_y = ((d * height) / ray->raylength) / 256;
		texture_color = get_texture_pixel(texture_img, texture_x, texture_y);
		put_pixel(cub->data, x, y, texture_color);
		y++;
	}
}

void	draw_cl_and_fl(t_cub *cub, t_ray *ray, int x)
{
	int	y;

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
