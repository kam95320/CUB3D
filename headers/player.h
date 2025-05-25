/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:48:16 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/24 14:55:43 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include <math.h>

#define FOV 60.0f
#define RAYS 60
#define DEG_TO_RAD(angle) ((angle) * M_PI / 180.0)

# define M_PI 3.14159265358979323846
# define SPACE 64
# define RATIO_PLAYER 8
# define RATIO_MOVE 4

# define MAP_VOID 0x353831
// # define MAP_WALL 0x090C08
# define MAP_WALL 0xFF0000
# define MAP_PLAYER 0x474056

# define MAP_SKY 0x778BF0
# define MAP_FLOOR 0x7C7C7C

# define MOVE_SPEED 0.2
# define ROTATE_SPEED 0.1

typedef struct s_player
{
	char	direction;
	int		rotation;
	int		player_move;
	double	fov_deg;

	double	fov_rad;
	char	dir;
	double	player_vw_lenght;
	double	radians;
	double	fl_pl_pos_y;
	double	fl_pl_pos_x;
	double	cam_pos_y;
	double	cam_pos_x;
	int		gesture_y;
	int		gesture_x;
	int		orig_pl_y;
	int		orig_pl_x;
	int		key;

}			t_player;

#endif // PLAYER_H