/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:42:53 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/24 20:01:45 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"


void	draw_vertical_line(t_cub *cub, int x, t_ray *ray, t_player *pl)
{
	void	*texture_img;
	int		texture_x;
	int		texture_y;
	int		texture_color;
	int		y;

	texture_img = get_texture(cub);
	ray->wall_x = calc_wall_hit(ray, pl);
	texture_x = (int)(ray->wall_x * 64.0);
	if (ray->whichside == 0 && ray->ray.x > 0)
		texture_x = 64 - texture_x - 1;
	if (ray->whichside == 1 && ray->ray.y < 0)
		texture_x = 64 - texture_x - 1;
	y = ray->startp;
	while (y < ray->endp)
	{
		texture_y = (int)(((y - ray->startp) * 64) / ray->raylength);
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
