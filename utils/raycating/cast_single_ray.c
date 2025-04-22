/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_single_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:23:46 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/22 16:49:51 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"
#include <math.h>

void	init_ray_steps(t_cub *cub, t_ray *ray)
{
	t_player	*pl;

	pl = cub->player;
	if (ray->ray.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (pl->fl_pl_pos_x - ray->map.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0 - pl->fl_pl_pos_x)
			* ray->deltadist.x;
	}
	if (ray->ray.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (pl->fl_pl_pos_y - ray->map.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0 - pl->fl_pl_pos_y)
			* ray->deltadist.y;
	}
}

void	init_ray_values(t_cub *cub, int x)
{
	t_ray		*ray;
	t_player	*pl;
	double		camera_x;

	ray = cub->ray;
	pl = cub->player;
	camera_x = 2.0 * x / (double)cub->data->width - 1.0;
	ray->ray.x = pl->cam_pos_x + ray->plane.x * camera_x;
	ray->ray.y = pl->cam_pos_y + ray->plane.y * camera_x;
	ray->map.x = (int)pl->fl_pl_pos_x;
	ray->map.y = (int)pl->fl_pl_pos_y;
	if (ray->ray.x == 0)
		ray->deltadist.x = 1e30;
	else
		ray->deltadist.x = fabs(1.0 / ray->ray.x);
	if (ray->ray.y == 0)
		ray->deltadist.y = 1e30;
	else
		ray->deltadist.y = fabs(1.0 / ray->ray.y);
}

void	cast_single_ray(t_cub *cub, int x)
{
	init_ray_values(cub, x);
	init_ray_steps(cub, cub->ray);
	perform_dda(cub);
	compute_perp_distance(cub);
	compute_ray_line(cub);
}
