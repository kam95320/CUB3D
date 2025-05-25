/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:27:45 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/24 19:07:29 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	step_ray(t_cub *cub)
{
	t_ray	*ray;

	ray = cub->ray;
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
}

int	ray_out_of_bounds(t_cub *cub)
{
	t_ray	*r;

	r = cub->ray;
	if (r->map.y < 0 || r->map.y >= cub->map->l)
	{
		// printf("pass in r->map.y\n");
		return (1);
	}
	if (!cub->map->matrix[r->map.y])
	{
		// printf("pass in cub->map->matrix[r->map.y]");
		return (1);
	}
	if (r->map.x < 0 || r->map.x >= (int)ft_strlen(cub->map->matrix[r->map.y]))
	{
		// printf("r->map.x < 0 || r->map.x >= (int)ft_strlen(cub->map->matrix[r->map.y]\n");
		return (1);
	}
	// if (cub->hit == 1)
	// {
	// 	printf("cub->hit  pass = %d", cub->hit);
	// 	return (1);
	// }
	return (0);
}

void	perform_dda(t_cub *cub)
{
	t_ray	*ray;
	int		hit =  cub->hit;
	ray = cub->ray;
	hit = 0;
	// printf(" while hit = %d\n", hit);
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
		if (ray_out_of_bounds(cub))
		{
			// printf("❌ Segfault évité : ray->map = (%d, %d)\n", ray->map.x,
			// ray->map.y);
			break ;
		}
		if (cub->map->matrix[ray->map.y][ray->map.x] == '1')
		{
			 hit = 1;
			// printf(GREEN"chocke wall = %d\n"RESET, hit);
		}
		
	}
}

void	compute_ray_line(t_cub *cub)
{
	t_ray	*ray;

	ray = cub->ray;
	ray->raylength = cub->data->height / ray->perpwalldist;
	ray->startp = -ray->raylength / 2 + cub->data->height / 2;
	if (ray->startp < 0)
	{
		ray->startp = 0;
	}
	ray->endp = ray->raylength / 2 + cub->data->height / 2;
	if (ray->endp >= cub->data->height)
	{
		ray->endp = cub->data->height - 1;
	}
}

void	compute_perp_distance(t_cub *cub)
{
	t_ray		*ray;
	t_player	*pl;

	ray = cub->ray;
	pl = cub->player;
	if (ray->whichside == 0)
	{
		ray->perpwalldist = (ray->map.x - pl->fl_pl_pos_x + (1 - ray->step.x)
				/ 2.0) / ray->ray.x;
	}
	else
	{

		ray->perpwalldist = (ray->map.y - pl->fl_pl_pos_y + (1 - ray->step.y)
				/ 2.0) / ray->ray.y;
	}
	if (ray->perpwalldist < 0.0001)
	{
		
		ray->perpwalldist = 0.0001;
	}
}
