/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ratioTextures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:40:49 by tespandj          #+#    #+#             */
/*   Updated: 2025/04/04 10:52:59 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
// void	texture_pixel(t_cub *cub, t_ray *ray)
// {
// 	int		length;
// 	int		color;
// 	int		pas;
// 	t_txt	*dir;

// 	printf("\n----texture_pixel deb ---\n");
// 	color = 0;
// 	dir = cardinalstxt(cub);
// 	ray->startp = ray->startp - 1;
// 	if (ray->startp < 0)
// 		ray->startp = 0;
// 	length = ray->raylength;
// 	pas = 1 * cub->txt[NO]->height / length;
// 	if (!cub->txt[NO] || !cub->txt[NO]->img)
// 	{
// 		printf("pass\n\n\n\n\n\n\n");
// 		printf("Erreur : texture NO non chargée !\n");
// 		exit(1);
// 	}
// 	cub->txt[NO]->addr = mlx_get_data_addr(cub->txt[NO]->img,
// 			&cub->txt[NO]->bits_per_pixel, &cub->txt[NO]->size_line,
// 			&cub->txt[NO]->endian);
// 	printf("cub->txt[NO]->addr = %p\n", cub->txt[NO]->addr);
// 	while (++ray->startp < ray->endp)
// 	{
// 		printf("\n----in while ray deb -----\n");
// 		printf("ray->startup  = %d < ray->endp =  %d\n", ray->startp, ray->endp);
// 		// color = (texture_buffer)[NO][cub->txt[NO]-> * ((int)pos & (MMAP - 1))
// 		// + tex_x];
// 		setpixel(cub->data, cub->ray->x, ray->startp, color);
// 		printf("\n----in while ray end -----\n");
// 	}
// 	(void)dir;
// 	(void)pas;
// 	printf("\n----texture_pixel end ---\n");
// }

// void debug_texture_pixel(t_cub *cub, t_ray *ray, t_txt *dir, int length, int pas)
// {
// 	printf("-----debug_texture_pixel----\n");
// 	printf("dir = %p", dir);
// 	printf("length =  %d\n", length);
// 	printf("ray->startp =  %d\n",  ray->startp);
// 	printf("pas = %d\n", pas);
// 	printf("cub->txt[NO]->addr = %p\n", cub->txt[NO]->addr);
	
// }
// void	texture_pixel(t_cub *cub, t_ray *ray)
// {
// 	int	length;
// 	int	color = 0;
// 	int	pas;
// 	t_txt	*dir;
// 	dir = cardinalstxt(cub);
// 	ray->startp = ray->startp - 1;
// 	if (ray->startp < 0)
// 	ray->startp = 0;
// 	length = ray->raylength;
// 	pas = 1 * cub->txt[NO]->height / length;
// 	cub->txt[NO]->addr = mlx_get_data_addr(cub->txt[NO]->img, &cub->txt[NO]->bits_per_pixel, &cub->txt[NO]->size_line, &cub->txt[NO]->endian);
// 	debug_texture_pixel(cub, ray, dir, length, pas);
// 	while (++ray->startp < ray->endp)
// 	{
// 		// color = (texture_buffer)[NO][cub->txt[NO]-> * ((int)pos & (MMAP - 1)) + tex_x];
// 		setpixel(cub->data, cub->ray->x, ray->startp, color);
// 	}
// 	(void)dir;
// 	(void)pas;
// }

void	debug_texture_pixel(t_txt *txt, t_ray *ray, int length, int pas)
{
	printf("-----debug_texture_pixel----\n");
	printf("length        = %d\n", length);
	printf("ray->startp   = %d\n", ray->startp);
	printf("pas           = %d\n", pas);
	printf("texture->addr = %p\n", txt->addr);
}

int	get_wall_direction(t_ray *ray)
{
	if (ray->whichside == 0)
		return (ray->step.x > 0 ? WE : EA);
	else
		return (ray->step.y > 0 ? NO : SO);
}


void	texture_pixel(t_cub *cub, t_ray *ray)
{
	int		length;
	int		color = 0;
	int		pas;
	t_txt	*txt;
	int		wall;

	wall = get_wall_direction(ray);
	txt = cub->txt[wall];

	if (!txt || !txt->img)
		wgas(cub, "texture_pixel", "Texture manquante pour cette direction");

	txt->addr = mlx_get_data_addr(txt->img, &txt->bits_per_pixel,
		&txt->size_line, &txt->endian);

	length = ray->raylength;
	if (length == 0)
		length = 1;
	pas = txt->height / length;

	ray->startp = ray->startp - 1;
	if (ray->startp < 0)
		ray->startp = 0;

	debug_texture_pixel(txt, ray, length, pas); // version à adapter

	while (++ray->startp < ray->endp)
	{
		// 🔥 ici tu mettras le calcul de tex_y puis get_color_from_texture()
		setpixel(cub->data, ray->x, ray->startp, color);
	}
}
