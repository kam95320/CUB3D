/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_direct_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:10:14 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/25 15:19:26 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	init_n_s(t_cub *cub, double pl_lenght)
{
	if (cub->player->dir == 'N')
	{
		cub->player->cam_pos_x = 0.0;
		cub->player->cam_pos_y = -1.0;
		cub->ray->plane.x = pl_lenght;
		cub->ray->plane.y = 0.0;
	}
	else if (cub->player->dir == 'S')
	{
		cub->player->cam_pos_x = 0.0;
		cub->player->cam_pos_y = 1.0;
		cub->ray->plane.x = pl_lenght;
		cub->ray->plane.y = 0.0;
	}
}

void	init_e_w(t_cub *cub, double pl_lenght)
{
	if (cub->player->dir == 'E')
	{
		cub->player->cam_pos_x = 1.0;
		cub->player->cam_pos_y = 0.0;
		cub->ray->plane.x = 0.0;
		cub->ray->plane.y = pl_lenght;
	}
	else if (cub->player->dir == 'W')
	{
		cub->player->cam_pos_x = -1.0;
		cub->player->cam_pos_y = 0.0;
		cub->ray->plane.x = 0.0;
		cub->ray->plane.y = -pl_lenght;
	}
}

void init_player_dir_cam(t_cub *cub, char direction)
{
	double pl_lenght = cub->player->player_vw_lenght;
    if (direction == 'N') {
		

		cub->player->cam_pos_x = 0.0;
        cub->player->cam_pos_y = -1.0;
        cub->ray->plane.x = pl_lenght;
        cub->ray->plane.y = 0.0;
    }
    else if (direction == 'S') {
		
		cub->player->cam_pos_x = 1.0;
        cub->player->cam_pos_y = 1.0;
        cub->ray->plane.x = -pl_lenght;
        cub->ray->plane.y = 0.0;
    }
    else if (direction == 'E') {
        cub->player->cam_pos_x = 1.0;
        cub->player->cam_pos_y = 0.0;
        cub->ray->plane.x = 0.0;
        cub->ray->plane.y = pl_lenght;
    }
    else if (direction == 'W') {
        cub->player->cam_pos_x = -1.0;
        cub->player->cam_pos_y = 0.0;
        cub->ray->plane.x = 0.0;
        cub->ray->plane.y = -pl_lenght;
    }
}



