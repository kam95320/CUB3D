/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data_initialization.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:33:59 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/02 17:26:52 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	player_data_initialization(t_player *data_player)
{
	data_player->direction = '\0';
	data_player->gesture_x = 0;
	data_player->gesture_y = 0;
	data_player->rotation = 0;
	data_player->player_move = 0;
	data_player->fl_pl_pos_x = 0.0;
	data_player->fl_pl_pos_y = 0.0;
	data_player->cam_pos_x = 0.0;
	data_player->cam_pos_y = 0.0;
}