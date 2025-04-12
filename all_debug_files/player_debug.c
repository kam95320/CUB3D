/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:55:25 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/12 19:54:43 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"


char *get_key_name(int key)
{
	if (key == 13)
		return "W";
	if (key == 0)
		return "A";
	if (key == 1)
		return "S";
	if (key == 2)
		return "D";
	if (key == 123)
		return "Left Arrow";
	if (key == 124)
		return "Right Arrow";
	if (key == 53)
		return "ESC";
	return "Unknown";
}

char *get_dir_icon(char dir)
{
	if (dir == 'N') return "↑ North";
	if (dir == 'S') return "↓ South";
	if (dir == 'E') return "→ East";
	if (dir == 'W') return "← West";
	return "Unknown";
}

// void	debug_player(t_player *player)
// {
// 	if (!player)
// 	{
// 		printf(RED "debug_player: pointer is NULL\n" RESET);
// 		return;
// 	}
// 	printf(CYAN "\n----- DEBUG PLAYER STRUCTURE -----\n" RESET);
// 	printf(YELLOW "Direction       : %c (%s)\n" RESET, player->direction, get_dir_icon(player->direction));
// 	printf(YELLOW "Rotation        : %d\n" RESET, player->rotation);
// 	printf(YELLOW "Player Move     : %d\n" RESET, player->player_move);
// 	printf(YELLOW "Radians         : %.4f\n" RESET, player->radians);
// 	printf(YELLOW "fl_pl_pos_x     : %.4f\n" RESET, player->fl_pl_pos_x);
// 	printf(YELLOW "fl_pl_pos_y     : %.4f\n" RESET, player->fl_pl_pos_y);
// 	printf(YELLOW "cam_pos_x       : %.4f\n" RESET, player->cam_pos_x);
// 	printf(YELLOW "cam_pos_y       : %.4f\n" RESET, player->cam_pos_y);
// 	printf(YELLOW "Gesture X       : %d\n" RESET, player->gesture_x);
// 	printf(YELLOW "Gesture Y       : %d\n" RESET, player->gesture_y);
// 	printf(YELLOW "Key             : %d (%s)\n" RESET, player->key, get_key_name(player->key));
// 	printf(CYAN "----------------------------------\n\n" RESET);
// }




void	debug_player(t_player *player)
{
	if (!player)
	{
		printf(RED "debug_player: player pointer is NULL\n" RESET);
		return;
	}

	printf(BLUE "\n----- DEBUG PLAYER STRUCTURE -----\n" RESET);
	printf(CYAN "Direction (char) : %c\n" RESET, player->dir);
	printf(CYAN "FOV (degrés)     : %.2f\n" RESET, player->fov_deg);
	printf(CYAN "FOV (radian)     : %.4f\n" RESET, player->fov_rad);
	printf(CYAN "Plan cam length  : %.4f\n" RESET, player->player_vw_lenght);
	printf(CYAN "Origine Map X/Y  : %d / %d\n" RESET, player->orig_pl_x, player->orig_pl_y);
	printf(CYAN "Position monde   : X = %.2f | Y = %.2f\n" RESET,
		player->fl_pl_pos_x, player->fl_pl_pos_y);
	printf(CYAN "Caméra pos X/Y   : %.2f / %.2f\n" RESET, player->cam_pos_x, player->cam_pos_y);
	printf(CYAN "Rotation         : %d\n" RESET, player->rotation);
	printf(CYAN "Déplacement      : %d\n" RESET, player->player_move);
	printf(CYAN "Gesture X/Y      : %d / %d\n" RESET, player->gesture_x, player->gesture_y);
	printf(CYAN "Touche active    : %d\n" RESET, player->key);
}
