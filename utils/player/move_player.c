/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:51:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/30 18:07:34 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"



void	move_player(t_cub *cub, double dx, double dy)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->fl_pl_pos_x + dx;
	new_y = cub->player->fl_pl_pos_y + dy;
	
	if (is_walkable_cell(cub, new_x, cub->player->fl_pl_pos_y))
		cub->player->fl_pl_pos_x = new_x;
	if (is_walkable_cell(cub, cub->player->fl_pl_pos_x, new_y))
		cub->player->fl_pl_pos_y = new_y;
}

void	key_player(t_cub *cub)
{
	if (cub->keys.key_straight == true)
		move_player(cub, cub->player->cam_pos_x * MOVE_SPEED,
			cub->player->cam_pos_y * MOVE_SPEED);

	if (cub->keys.key_back)
		move_player(cub, -cub->player->cam_pos_x * MOVE_SPEED,
			-cub->player->cam_pos_y * MOVE_SPEED);

	if (cub->keys.key_right)
		move_player(cub, -cub->player->cam_pos_y * MOVE_SPEED,
			cub->player->cam_pos_x * MOVE_SPEED);
	if (cub->keys.key_left)
		move_player(cub, cub->player->cam_pos_y * MOVE_SPEED,
			-cub->player->cam_pos_x * MOVE_SPEED);

	if (cub->keys.cam_left)
		rotate_left(cub);
	if (cub->keys.cam_right)
		rotate_right(cub);
}
