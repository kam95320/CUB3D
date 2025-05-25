/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:20:57 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/17 22:46:56 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"



void	vec2i_debug(char *param_x, char *param_y, t_mgam2i veci)
{
	printf(LIGHT_PURPLE "%s = %d | %s = %d\n" RESET, param_x, veci.x, param_y, veci.y);
}

void	vec2f_debug(char *param_x, char *param_y, t_mgam2f vecf)
{
	printf(LIGHT_PURPLE "%s = %.4f | %s = %.4f\n" RESET, param_x, vecf.x, param_y, vecf.y);
}

void	debug_raycasting(t_ray *ray)
{
	printf(MUTED_PURPLE "\n----- RAYCASTING VECTEURS -----\n" RESET);
	vec2i_debug("map.x", "map.y", ray->map);
	vec2i_debug("step.x", "step.y", ray->step);
	vec2f_debug("ray.x", "ray.y", ray->ray);
	vec2f_debug("plane.x", "plane.y", ray->plane);
	vec2f_debug("sidedist.x", "sidedist.y", ray->sidedist);
	vec2f_debug("deltadist.x", "deltadist.y", ray->deltadist);
	printf(LIGHT_PURPLE "raylength = %d\n" RESET, ray->raylength);
	printf(LIGHT_PURPLE "whichside = %d\n" RESET, ray->whichside);
	printf(LIGHT_PURPLE "startp    = %d\n" RESET, ray->startp);
	printf(LIGHT_PURPLE "endp      = %d\n" RESET, ray->endp);
}
