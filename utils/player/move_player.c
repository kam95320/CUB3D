/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:51:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/25 17:34:00 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	move_straight(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->fl_pl_pos_x + cub->player->cam_pos_x * MOVE_SPEED;
	new_y = cub->player->fl_pl_pos_y + cub->player->cam_pos_y * MOVE_SPEED;
	if (is_walkable_cell(cub, new_x, new_y))
	{
		cub->player->fl_pl_pos_x = new_x;
		cub->player->fl_pl_pos_y = new_y;
	}
	if (new_x >= 0 && new_x < cub->data->line_length && new_y >= 0
		&& new_y < cub->data->height
		&& cub->map->matrix[(int)new_y][(int)new_x] != '1')
	{
		cub->player->fl_pl_pos_x = new_x;
		cub->player->fl_pl_pos_y = new_y;
	}
}

void	move_back(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->fl_pl_pos_x - cub->player->cam_pos_x * MOVE_SPEED;
	new_y = cub->player->fl_pl_pos_y - cub->player->cam_pos_y * MOVE_SPEED;
    if (is_walkable_cell(cub, new_x, new_y))
	{
		cub->player->fl_pl_pos_x = new_x;
		cub->player->fl_pl_pos_y = new_y;
	}
	if (new_x >= 0 && new_x < cub->data->line_length && new_y >= 0
		&& new_y < cub->data->height
		&& cub->map->matrix[(int)new_y][(int)new_x] != '1')
	{
		cub->player->fl_pl_pos_x = new_x;
		cub->player->fl_pl_pos_y = new_y;
	}
}

// #define MARGIN 0.2

// void	move_back(t_cub *cub)
// {
// 	t_player	*pl;
// 	double		new_x;
// 	double		new_y;

// 	pl = cub->player;
// 	new_x = pl->fl_pl_pos_x - pl->cam_pos_x * MOVE_SPEED;
// 	new_y = pl->fl_pl_pos_y - pl->cam_pos_y * MOVE_SPEED;

// 	if (is_walkable_cell(cub, new_x - MARGIN * pl->cam_pos_x, pl->fl_pl_pos_y))
// 		pl->fl_pl_pos_x = new_x;
// 	if (is_walkable_cell(cub, pl->fl_pl_pos_x, new_y - MARGIN * pl->cam_pos_y))
// 		pl->fl_pl_pos_y = new_y;
// }

void	move_right(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->fl_pl_pos_x + cub->ray->plane.x * MOVE_SPEED;
	new_y = cub->player->fl_pl_pos_y + cub->ray->plane.y * MOVE_SPEED;
    if (is_walkable_cell(cub, new_x, new_y))
	{
		cub->player->fl_pl_pos_x = new_x;
		cub->player->fl_pl_pos_y = new_y;
	}
	if (new_x >= 0 && new_x < cub->data->line_length && new_y >= 0
		&& new_y < cub->data->height
		&& cub->map->matrix[(int)new_y][(int)new_x] != '1')
	{
		cub->player->fl_pl_pos_x = new_x;
		cub->player->fl_pl_pos_y = new_y;
	}
}

void	move_left(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->fl_pl_pos_x - cub->ray->plane.x * MOVE_SPEED;
	new_y = cub->player->fl_pl_pos_y - cub->ray->plane.y * MOVE_SPEED;
    if (is_walkable_cell(cub, new_x, new_y) == 1)
	{
		cub->player->fl_pl_pos_x = new_x;
		cub->player->fl_pl_pos_y = new_y;
	}
	if (new_x >= 0 && new_x < cub->data->line_length && new_y >= 0
		&& new_y < cub->data->height
		&& cub->map->matrix[(int)new_y][(int)new_x] != '1')
	{
		cub->player->fl_pl_pos_x = new_x;
		cub->player->fl_pl_pos_y = new_y;
	}
}

// //sweep  on  the wall


// void	move_straight(t_cub *cub)
// {
// 	t_player	*pl = cub->player;
// 	double		new_x = pl->fl_pl_pos_x + pl->cam_pos_x * MOVE_SPEED;
// 	double		new_y = pl->fl_pl_pos_y + pl->cam_pos_y * MOVE_SPEED;

// 	if (is_walkable_cell(cub, new_x, pl->fl_pl_pos_y))
// 		pl->fl_pl_pos_x = new_x;
// 	if (is_walkable_cell(cub, pl->fl_pl_pos_x, new_y))
// 		pl->fl_pl_pos_y = new_y;
// }
// void	move_back(t_cub *cub)
// {
// 	t_player	*pl = cub->player;
// 	double		new_x = pl->fl_pl_pos_x - pl->cam_pos_x * MOVE_SPEED;
// 	double		new_y = pl->fl_pl_pos_y - pl->cam_pos_y * MOVE_SPEED;

// 	if (is_walkable_cell(cub, new_x, pl->fl_pl_pos_y))
// 		pl->fl_pl_pos_x = new_x;
// 	if (is_walkable_cell(cub, pl->fl_pl_pos_x, new_y))
// 		pl->fl_pl_pos_y = new_y;
// }
// void	move_right(t_cub *cub)
// {
// 	t_player	*pl = cub->player;
// 	t_ray		*ray = cub->ray;
// 	double		new_x = pl->fl_pl_pos_x + ray->plane.x * MOVE_SPEED;
// 	double		new_y = pl->fl_pl_pos_y + ray->plane.y * MOVE_SPEED;

// 	if (is_walkable_cell(cub, new_x, pl->fl_pl_pos_y))
// 		pl->fl_pl_pos_x = new_x;
// 	if (is_walkable_cell(cub, pl->fl_pl_pos_x, new_y))
// 		pl->fl_pl_pos_y = new_y;
// // }

// void	move_left(t_cub *cub)
// {
// 	t_player	*pl = cub->player;
// 	t_ray		*ray = cub->ray;
// 	double		new_x = pl->fl_pl_pos_x - ray->plane.x * MOVE_SPEED;
// 	double		new_y = pl->fl_pl_pos_y - ray->plane.y * MOVE_SPEED;

// 	if (is_walkable_cell(cub, new_x, pl->fl_pl_pos_y))
// 		pl->fl_pl_pos_x = new_x;
// 	if (is_walkable_cell(cub, pl->fl_pl_pos_x, new_y))
// 		pl->fl_pl_pos_y = new_y;
// }


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
	if (cub->keys.cam_left)
		rotate_left(cub);
	if (cub->keys.cam_right)
		rotate_right(cub);
}
