/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_single_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:23:46 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/14 16:24:15 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../headers/utils.h"

void	cast_single_ray(t_cub *cub, int x)
{
	t_ray		*ray;
	t_player	*pl;
	double		camera_x;
	int			hit;

	ray = cub->ray;
	pl = cub->player;
	camera_x = 2.0 * x / (double)cub->win_width - 1.0;

	// Direction du rayon
	ray->ray.x = pl->cam_pos_x + ray->plane.x * camera_x;
	ray->ray.y = pl->cam_pos_y + ray->plane.y * camera_x;

	// Position sur la carte
	ray->map.x = (int)pl->fl_pl_pos_x;
	ray->map.y = (int)pl->fl_pl_pos_y;

	// Calcul des distances delta
	if (ray->ray.x == 0)
		ray->deltadist.x = 1e30;
	else
		ray->deltadist.x = fabs(1.0 / ray->ray.x);
	if (ray->ray.y == 0)
		ray->deltadist.y = 1e30;
	else
		ray->deltadist.y = fabs(1.0 / ray->ray.y);

	// Calcul des étapes et des distances latérales
	if (ray->ray.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (pl->fl_pl_pos_x - ray->map.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0 - pl->fl_pl_pos_x) * ray->deltadist.x;
	}
	if (ray->ray.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (pl->fl_pl_pos_y - ray->map.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0 - pl->fl_pl_pos_y) * ray->deltadist.y;
	}

	// Détection de mur (DDA)
	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			ray->whichside = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			ray->whichside = 1;
		}
		if (cub->map->matrix[ray->map.y][ray->map.x] == '1')
			hit = 1;
	}

	// Calcul de la distance perpendiculaire au mur
	if (ray->whichside == 0)
		ray->perpwalldist = (ray->map.x - pl->fl_pl_pos_x + (1 - ray->step.x) / 2.0) / ray->ray.x;
	else
		ray->perpwalldist = (ray->map.y - pl->fl_pl_pos_y + (1 - ray->step.y) / 2.0) / ray->ray.y;

	// Calcul de la hauteur de la ligne à dessiner
	ray->raylength = (int)(cub->win_height / ray->perpwalldist);

	// Calcul des positions de début et de fin de la ligne
	ray->startp = -ray->raylength / 2 + cub->win_height / 2;
	if (ray->startp < 0)
		ray->startp = 0;
	ray->endp = ray->raylength / 2 + cub->win_height / 2;
	if (ray->endp >= cub->win_height)
		ray->endp = cub->win_height - 1;
}
