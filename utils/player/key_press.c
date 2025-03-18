/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:00:57 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/18 14:16:39 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	key_press(t_player *player)
{
	if (player->key == KEY_W)
	{
		player->fl_pl_pos_x = cos(player->radians) * MOVE_SPEED;
		player->fl_pl_pos_y = sin(player->radians) * MOVE_SPEED;
	}
	if (player->key == KEY_S)
	{
		player->fl_pl_pos_x = cos(player->radians) * MOVE_SPEED;
		player->fl_pl_pos_y = sin(player->radians) * MOVE_SPEED;
	}
	if (player->key == KEY_A)
	{
		player->fl_pl_pos_x = cos(player->radians + PI / 2) * MOVE_SPEED;
		player->fl_pl_pos_y = sin(player->radians + PI / 2) * MOVE_SPEED;
	}
	if (player->key == KEY_D)
	{
		player->fl_pl_pos_x = cos(player->radians + PI / 2) * MOVE_SPEED;
		player->fl_pl_pos_y = sin(player->radians + PI / 2) * MOVE_SPEED;
	}
	if (player->key == KEY_LEFT)
		player->radians -= ROT_SPEED;
	if (player->key == KEY_RIGHT)
		player->radians -= ROT_SPEED;
}
