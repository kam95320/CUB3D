/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_pl_e_w.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:33:12 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/29 19:08:14 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../../headers/utils.h"

void	init_var_pl_e_w(t_player *player)
{
	if (player->direction == 'W')
	{
		player->fl_pl_pos_x = 0;
		player->fl_pl_pos_y = 1;
		player->cam_pos_x = 0;
		player->cam_pos_y = 0.66;
	}
	else if (player->direction == 'E')
	{
		player->fl_pl_pos_x = 0;
		player->fl_pl_pos_y = 1;
		player->cam_pos_x = 0.66;
		player->cam_pos_y = 0;
	}
	else
		return ;
}
