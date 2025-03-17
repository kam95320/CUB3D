/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:48:16 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/17 15:40:19 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_player
{
	char	direction;
	int		rotation;
	int		player_move;
	double	fl_pl_pos_y;
	double	fl_pl_pos_x;
	double	cam_pos_y;
	double	cam_pos_x;
	int		gesture_y;
	int		gesture_x;

	
}			t_player;
void init_player(t_player *player, char **map);
void find_player(t_player *player, char **map);
char **find_map_start(char **map);

#endif // PLAYER_H