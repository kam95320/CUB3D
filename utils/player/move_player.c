/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:51:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/15 15:55:49 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	w_key(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->cam_pos_x;
	new_y = cub->player->cam_pos_y - MOVE_SPEED;
	if (cub->map->matrix[(int)new_y][(int)new_x] != '1')
		cub->player->cam_pos_y = new_y;
}

void	s_key(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->cam_pos_x;
	new_y = cub->player->cam_pos_y + MOVE_SPEED;
	if (cub->map->matrix[(int)new_y][(int)new_x] != '1')
		cub->player->cam_pos_y = new_y;
}

void	a_key(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->cam_pos_x - MOVE_SPEED;
	new_y = cub->player->cam_pos_y;
	if (cub->map->matrix[(int)new_y][(int)new_x] != '1')
		cub->player->cam_pos_x = new_x;
}

void	d_key(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->cam_pos_x + MOVE_SPEED;
	new_y = cub->player->cam_pos_y;
	if (cub->map->matrix[(int)new_y][(int)new_x] != '1')
		cub->player->cam_pos_x = new_x;
}

void	action_key(t_cub *cub)
{
	if (cub->keys.key_up == true)
		w_key(cub);
	if (cub->keys.key_down == true)
		s_key(cub);
	if (cub->keys.key_left == true)
		a_key(cub);
	if (cub->keys.key_right == true)
		d_key(cub);
	if (cub->keys.cam_left == true)
		rotate_left(cub);
	if (cub->keys.cam_right == true)
		rotate_right(cub);
}

