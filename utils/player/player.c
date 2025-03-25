/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:52:18 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/25 20:15:32 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void init_player(t_player *player, char **map, t_map *my_map)
{
    
    char **map_start = find_map_start(map);
    find_player(player, map_start);
    key_press(player);
    player_move(player,  my_map);
}

