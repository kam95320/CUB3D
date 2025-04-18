/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:51:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/18 17:28:26 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

// void	w_key(t_cub *cub)
// {
// 	double	new_x;
// 	double	new_y;

// 	new_x = cub->player->cam_pos_x;
// 	new_y = cub->player->cam_pos_y - MOVE_SPEED;
// 	if (cub->map->matrix[(int)new_y][(int)new_x] != '1')
// 		cub->player->cam_pos_y = new_y;
// }

// void	s_key(t_cub *cub)
// {
// 	double	new_x;
// 	double	new_y;

// 	new_x = cub->player->cam_pos_x;
// 	new_y = cub->player->cam_pos_y + MOVE_SPEED;
// 	if (cub->map->matrix[(int)new_y][(int)new_x] != '1')
// 		cub->player->cam_pos_y = new_y;
// }

// void	a_key(t_cub *cub)
// {
// 	double	new_x;
// 	double	new_y;

// 	new_x = cub->player->cam_pos_x - MOVE_SPEED;
// 	new_y = cub->player->cam_pos_y;
// 	if (cub->map->matrix[(int)new_y][(int)new_x] != '1')
// 		cub->player->cam_pos_x = new_x;
// }

// void	d_key(t_cub *cub)
// {
// 	double	new_x;
// 	double	new_y;

// 	new_x = cub->player->cam_pos_x + MOVE_SPEED;
// 	new_y = cub->player->cam_pos_y;
// 	if (cub->map->matrix[(int)new_y][(int)new_x] != '1')
// 		cub->player->cam_pos_x = new_x;
// }

// void	w_key(t_cub *cub)
// {
// 	double	new_x;
// 	double	new_y;

// 	new_x = cub->player->cam_pos_x - MOVE_SPEED;
// 	new_y = cub->player->cam_pos_y;
// 	if (cub->map->matrix[(int)new_y][(int)new_x] != '1')
// 		cub->player->cam_pos_x = new_x;
// }

// void	d_key(t_cub *cub)
// {
// 	double	new_x;
// 	double	new_y;

// 	new_x = cub->player->cam_pos_x;
// 	new_y = cub->player->cam_pos_y - MOVE_SPEED;
// 	if (cub->map->matrix[(int)new_y][(int)new_x] != '1')
// 		cub->player->cam_pos_y = new_y;
// }
// void	s_key(t_cub *cub)
// {
// 	double	new_x;
// 	double	new_y;

// 	new_x = cub->player->cam_pos_x + MOVE_SPEED;
// 	new_y = cub->player->cam_pos_y;
// 	if (cub->map->matrix[(int)new_y][(int)new_x] != '1')
// 		cub->player->cam_pos_x = new_x;
// }

// void a_key(t_cub *cub)
// {
// 	double	new_x;
// 	double	new_y;

// 	new_x = cub->player->cam_pos_x;
// 	new_y = cub->player->cam_pos_y + MOVE_SPEED;
// 	if (cub->map->matrix[(int)new_y][(int)new_x] != '1')
// 		cub->player->cam_pos_y = new_y;
// }

// void	action_key(t_cub *cub)
// {
// 	if (cub->keys.key_up == true)
// 		w_key(cub);
// 	if (cub->keys.key_down == true)
// 		s_key(cub);
// 	if (cub->keys.key_left == true)
// 		a_key(cub);
// 	if (cub->keys.key_right == true)
// 		d_key(cub);
// 	if (cub->keys.cam_left == true)
// 		rotate_left(cub);
// 	if (cub->keys.cam_right == true)
// 		rotate_right(cub);
// }

void	move_straight(t_cub *cub)
{
	double	move_y;
	double	move_x;

	move_x = cub->player->cam_pos_x - MOVE_SPEED;
	move_y = cub->player->cam_pos_y;
	if (cub->map->matrix[(int)move_y][(int)move_x] != '1')
		cub->player->cam_pos_x = move_x;
}

void	move_back(t_cub *cub)
{
	double	move_y;
	double	move_x;

	move_x = cub->player->cam_pos_x + MOVE_SPEED;
	move_y = cub->player->cam_pos_y;
	if (cub->map->matrix[(int)move_y][(int)move_x] != '1')
		cub->player->cam_pos_x = move_x;
}
void	move_right(t_cub *cub)
{
	printf("\n----- move_right deb ------\n");
	double	move_y;
	double	move_x;

	move_y = cub->player->cam_pos_y - MOVE_SPEED;
	move_x = cub->player->cam_pos_x;
	if (cub->map->matrix[(int)move_y][(int)move_x] != '1')
	{
		printf("position in map  key  right = %d \n",
			cub->map->matrix[(int)move_y][(int)move_x]);
		printf("right move  calculi = move_y =  %f | move_x =  %f\n", move_y,
			move_x);
		cub->player->cam_pos_y = move_y;
	}
	printf("\n----- move_right end ------\n");

}

void	move_left(t_cub *cub)
{

	printf("\n----- move_left deb ------\n");
	
	double	move_y;
	double	move_x;

	move_y = cub->player->cam_pos_y + MOVE_SPEED;
	move_x = cub->player->cam_pos_x -  MOVE_SPEED;
	if (cub->map->matrix[(int)move_y][(int)move_x] != '1')
	{
		printf("position in map  key  right = %d \n",
			cub->map->matrix[(int)move_y][(int)move_x]);
		printf("left move  calculi = move_y =  %f | move_x =  %f\n", move_y,
			move_x);
		cub->player->cam_pos_y = move_y;
	}
	printf("\n----- move_left end ------\n");

}

void	key_player(t_cub *cub)
{
	if (cub->keys.key_straight == true)
		move_straight(cub);
	if (cub->keys.key_back)
		move_back(cub);
	if (cub->keys.key_right)
		move_right(cub);
	if (cub->keys.key_left)
		move_left(cub);
}
