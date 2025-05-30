/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_pl_n_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:07:39 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/24 19:48:27 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../../headers/utils.h"

void	init_var_pl_n_s(t_player *player)
{
	if (player->direction == 'S')
	{
		player->fl_pl_pos_x = 0;
		player->fl_pl_pos_y = 1;
		player->cam_pos_x = 0.66;
		player->cam_pos_y = 0;
	}
	else if (player-> direction == 'N')
	{
		player->fl_pl_pos_x = 0;
		player->fl_pl_pos_y = -1;
		player->cam_pos_x = 0.66;
		player->cam_pos_y = 0;
	}
	else
		return ;
}

