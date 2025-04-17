/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calc_debug.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:55:37 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/17 16:58:33 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	single_ray_debug(t_cub *cub, int x)
{
	t_ray		*ray;
	t_player	*pl;

	ray = cub->ray;
	pl = cub->player;
	printf(MUTED_PURPLE"\n🧪 ----- DEBUG RAY #%d -----\n"RESET, x);
	printf(LIGHT_PURPLE"📍 Player position (fl_pl_pos): %.2f, %.2f\n" RESET, pl->fl_pl_pos_x,
		pl->fl_pl_pos_y);
	printf(LIGHT_PURPLE"🎯 Camera X: %.6f\n"RESET, ray->camerax);
	printf(LIGHT_PURPLE"➡️  Ray direction: ray.x = %.6f | ray.y = %.6f\n", ray->ray.x,
		ray->ray.y);
	printf(LIGHT_PURPLE"📌 Map cell: map.x = %d | map.y = %d\n"RESET, ray->map.x, ray->map.y);
	printf(LIGHT_PURPLE"📏 Delta dist: deltadist.x = %.6f | deltadist.y = %.6f\n"RESET,
		ray->deltadist.x, ray->deltadist.y);
	printf(LIGHT_PURPLE"🚶 Step: step.x = %d | step.y = %d\n"RESET, ray->step.x, ray->step.y);
	printf(LIGHT_PURPLE"⏱️  Side dist: sidedist.x = %.6f | sidedist.y = %.6f\n"RESET,
		ray->sidedist.x, ray->sidedist.y);
	printf(LIGHT_PURPLE"🧱 Wall hit side: whichside = %d (%s)\n"RESET, ray->whichside,
		ray->whichside == 0 ? "vertical" : "horizontal");
	printf(LIGHT_PURPLE"📐 Perpendicular wall distance: %.6f\n"RESET, ray->perpwalldist);
	printf(LIGHT_PURPLE"📏 Ray line height: %d\n"RESET, ray->raylength);
	printf(LIGHT_PURPLE"📍 Draw start = %d | end = %d\n"RESET, ray->startp, ray->endp);
	printf(MUTED_PURPLE"🧪 --------------------------\n"RESET);
}


void	debug_draw_vertical_line(t_cub *cub, int x)
{
	t_ray *ray = cub->ray;

	printf(BLUE"\n🎨 ----- DEBUG DRAW COLUMN #%d -----\n"RESET, x);
	printf(CYAN"🧱 Wall direction: %s\n", 
		(ray->whichside == 0 && ray->ray.x < 0) ? "West" :
		(ray->whichside == 0 && ray->ray.x >= 0) ? "East" :
		(ray->whichside == 1 && ray->ray.y < 0) ? "North" : "South"RESET);
	printf(CYAN"📐 perpwalldist: %.4f\n"RESET, ray->perpwalldist);
	printf(CYAN"📏 lineheight  : %d\n"RESET, ray->raylength);
	printf(CYAN"🖼️ texture_x   : %d (calculated from perpwalldist)\n" RESET, 
		(int)(ray->perpwalldist * 64) % 64);
	printf(CYAN"🧍 startp      : %d\n"RESET, ray->startp);
	printf(CYAN"🧍 endp        : %d\n"RESET, ray->endp);
	printf(CYAN"🖼️ image width : %d | height: %d\n"RESET, 
		cub->data->width, cub->data->height);
	printf(BLUE"🎨 -------------------------------\n" RESET);
}



void	debug_draw_cl_and_fl(t_cub *cub, t_ray *ray, int x)
{
	printf(GREEN"\n🧱 ----- DEBUG FLOOR/CEILING COLUMN #%d -----\n" RESET, x);
	printf(SOFT_GREEN"🌫️  Ceiling color (hex) : 0x%06X\n"RESET, cub->map->ceiling_cl_hx);
	printf(SOFT_GREEN"🌍 Floor color (hex)    : 0x%06X\n", cub->map->floor_cl_hx);
	printf("⬆️  draw ceiling y ∈ [0, %d[\n", ray->startp);
	printf("⬇️  draw floor   y ∈ [%d, %d[\n", ray->startp, cub->data->height);
	printf("🖼️ image height         : %d\n"RESET, cub->data->height);
	printf(GREEN"🧱 -----------------------------\n"RESET);
}

void debg_ray_calc(t_cub  *cub, int x)
{
    printf(CYAN"\n|----------DEBUG RAYCASTING CALCULI----------|\n"RESET);
    single_ray_debug(cub, x);
    debug_draw_vertical_line(cub, x); 
    debug_draw_cl_and_fl(cub, cub->ray,  x); 
}


