/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:01:06 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/17 23:05:57 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void rotate_right(t_cub *cub)
{
    double cos_theta = cos(ROTATE_SPEED);
    double sin_theta = sin(ROTATE_SPEED);
    double old_dir_x = cub->player->cam_pos_x;
    cub->player->cam_pos_x = old_dir_x * cos_theta - cub->player->cam_pos_y * sin_theta;
    cub->player->cam_pos_y = old_dir_x * sin_theta + cub->player->cam_pos_y * cos_theta;
    double old_plane_x = cub->ray->plane.x;
    cub->ray->plane.x = old_plane_x * cos_theta - cub->ray->plane.y * sin_theta;
    cub->ray->plane.y = old_plane_x * sin_theta + cub->ray->plane.y * cos_theta;
}

void rotate_left(t_cub *cub)
{
    double cos_theta = cos(ROTATE_SPEED);
    double sin_theta = -sin(ROTATE_SPEED);
    double old_dir_x = cub->player->cam_pos_x;
    cub->player->cam_pos_x = old_dir_x * cos_theta - cub->player->cam_pos_y * sin_theta;
    cub->player->cam_pos_y = old_dir_x * sin_theta + cub->player->cam_pos_y * cos_theta;
    double old_plane_x = cub->ray->plane.x;
    cub->ray->plane.x = old_plane_x * cos_theta - cub->ray->plane.y * sin_theta;
    cub->ray->plane.y = old_plane_x * sin_theta + cub->ray->plane.y * cos_theta;
}