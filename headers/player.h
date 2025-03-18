/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:48:16 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/18 14:10:55 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include <math.h>

# define KEY_W 119       // Z = Avancer
# define KEY_A 97        // Q = Gauche
# define KEY_S 115       // S = Reculer
# define KEY_D 100       // D = Droite
# define KEY_LEFT 65361  // Flèche gauche
# define KEY_RIGHT 65363 // Flèche droite
# define MOVE_SPEED 0.1  // Vitesse de déplacement
# define ROT_SPEED 0.05  // Vitesse de rotation
# define PI 3.14159265358979323846
typedef struct s_player
{
	char	direction;
	int		rotation;
	int		player_move;
	double	radians;
	double	fl_pl_pos_y;
	double	fl_pl_pos_x;
	double	cam_pos_y;
	double	cam_pos_x;
	int		gesture_y;
	int		gesture_x;
	int		key;

}			t_player;
void		init_player(t_player *player, char **map);
void		find_player(t_player *player, char **map);
char		**find_map_start(char **map);
int	key_press(t_player *player)

#endif // PLAYER_H