/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:10:34 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/19 17:56:02 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	player_move(t_player *player, t_map *map)
{
	int y;
	int x;
	x = 0;
	y = 0;

	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->file[y][x] == 'N')
			{
				player->fl_pl_pos_x = x + 0.5;
				player->fl_pl_pos_y = y + 0.5;
                player->radians = PI / 2;
			}
		}
		y++;
	}
}