/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:51:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/21 16:30:27 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	move_straight(t_cub *cub)
{
	double	move_y;
	double	move_x;

	move_x = cub->player->cam_pos_x - MOVE_SPEED;
	move_y = cub->player->cam_pos_y;
	if (cub->map->matrix[(int)move_y][(int)move_x] != '1')
		cub->player->cam_pos_x = move_x;
}

void	move_back(t_cub *cub)
{
	double	move_y;
	double	move_x;

	move_x = cub->player->cam_pos_x + MOVE_SPEED;
	move_y = cub->player->cam_pos_y;
	if (cub->map->matrix[(int)move_y][(int)move_x] != '1')
		cub->player->cam_pos_x = move_x;
}

void	move_right(t_cub *cub)
{
	double	move_y;
	double	move_x;

	move_y = cub->player->cam_pos_y - MOVE_SPEED;
	move_x = cub->player->cam_pos_x;
	if (cub->map->matrix[(int)move_y][(int)move_x] != '1')
		cub->player->cam_pos_y = move_y;
}

void	move_left(t_cub *cub)
{
	double	move_y;
	double	move_x;

	move_y = cub->player->cam_pos_y + MOVE_SPEED;
	move_x = cub->player->cam_pos_x - MOVE_SPEED;
	if (cub->map->matrix[(int)move_y][(int)move_x] != '1')
		cub->player->cam_pos_y = move_y;
}

void	key_player(t_cub *cub)
{
	if (cub->keys.key_straight == true)
		move_straight(cub);
	if (cub->keys.key_back)
		move_back(cub);
	if (cub->keys.key_right)
		move_right(cub);
	if (cub->keys.key_left)
		move_left(cub);
}
