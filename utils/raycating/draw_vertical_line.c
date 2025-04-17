/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:42:53 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/17 17:14:41 by kahoumou         ###   ########.fr       */
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
	t_ray		*ray = cub->ray;
	t_player	*pl = cub->player;
	void		*texture_img;
	int			texture_x, texture_y, texture_color;
	int			texture_width, texture_height;
	double		wall_x;
	int			y;

	// Choisir la bonne texture
	if (ray->whichside == 0)
		texture_img = (ray->ray.x < 0) ? cub->txt[WE]->img : cub->txt[EA]->img;
	else
		texture_img = (ray->ray.y < 0) ? cub->txt[NO]->img : cub->txt[SO]->img;

	texture_width = 64;  // ou cub->txt[...] si tu veux passer dynamiquement
	texture_height = 64;

	// Calcule le point d’impact du rayon sur le mur
	if (ray->whichside == 0)
		wall_x = pl->fl_pl_pos_y + ray->perpwalldist * ray->ray.y;
	else
		wall_x = pl->fl_pl_pos_x + ray->perpwalldist * ray->ray.x;
	wall_x -= floor(wall_x); // partie fractionnaire uniquement

	// Calcul de la coordonnée X dans la texture
	texture_x = (int)(wall_x * (double)texture_width);
	if (ray->whichside == 0 && ray->ray.x > 0)
		texture_x = texture_width - texture_x - 1;
	if (ray->whichside == 1 && ray->ray.y < 0)
		texture_x = texture_width - texture_x - 1;

	y = ray->startp;
	while (y < ray->endp)
	{
		texture_y = (int)(((y - ray->startp) * texture_height) / ray->raylength);
		texture_color = get_texture_pixel(texture_img, texture_x, texture_y);
		put_pixel(cub->data, x, y, texture_color);
		y++;
	}
}




void	draw_cl_and_fl(t_cub *cub, t_ray *ray, int x)
{
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


