/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:49:03 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/31 15:58:48 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

typedef struct s_raycasting
{
	double	cam_p_x;
	double	ray_rayon_d_y;
	double	ray_rayon_d_x;
	int		ray_map_p_y;
	int		ray_map_p_x;
	int		ray_evol_y;
	int		ray_evol_x;
	int		ray_cel_dist_y;
	int		ray_cel_dist_x;
	double	ray_axe_dist_y;
	double	ray_axe_dist_x;
	double	ray_wall_dist;
	double	ray_pos_wall_y;
	double	ray_pos_wall_x;
	int		ray_wall_touch;
	int		ray_line_start;
	int		ray_line_end;

}			t_raycasting;

#endif //  RAYCASTING_H