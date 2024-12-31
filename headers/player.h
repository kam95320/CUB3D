/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:48:16 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/31 15:58:52 by kahoumou         ###   ########.fr       */
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

#endif // PLAYER_H