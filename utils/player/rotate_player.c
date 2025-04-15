/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:01:06 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/15 16:07:25 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"


void	rotate_left(t_cub *cub)
{
	double	old_dir_x = cub->player->cam_pos_x;
	double	old_plane_x = cub->player->fl_pl_pos_x;

	cub->player->cam_pos_x = cub->player->cam_pos_x * cos(-ROTATE_SPEED)
		- cub->player->cam_pos_y * sin(-ROTATE_SPEED);
	cub->player->cam_pos_y = old_dir_x * sin(-ROTATE_SPEED)
		+ cub->player->cam_pos_y * cos(-ROTATE_SPEED);

	cub->player->fl_pl_pos_x = cub->player->fl_pl_pos_x * cos(-ROTATE_SPEED)
		- cub->player->fl_pl_pos_y * sin(-ROTATE_SPEED);
	cub->player->fl_pl_pos_y = old_plane_x * sin(-ROTATE_SPEED)
		+ cub->player->fl_pl_pos_y * cos(-ROTATE_SPEED);
}

void	rotate_right(t_cub *cub)
{
	double	old_dir_x = cub->player->cam_pos_x;
	double	old_plane_x = cub->player->fl_pl_pos_x;

	cub->player->cam_pos_x = cub->player->cam_pos_x * cos(ROTATE_SPEED)
		- cub->player->cam_pos_y * sin(ROTATE_SPEED);
	cub->player->cam_pos_y = old_dir_x * sin(ROTATE_SPEED)
		+ cub->player->cam_pos_y * cos(ROTATE_SPEED);

	cub->player->fl_pl_pos_x = cub->player->fl_pl_pos_x * cos(ROTATE_SPEED)
		- cub->player->fl_pl_pos_y * sin(ROTATE_SPEED);
	cub->player->fl_pl_pos_y = old_plane_x * sin(ROTATE_SPEED)
		+ cub->player->fl_pl_pos_y * cos(ROTATE_SPEED);
}
