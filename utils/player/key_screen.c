/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:06:56 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/21 16:31:49 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	key_press(int code, t_cub *cub)
{
	if (code == ESC_KEY)
		mlx_loop_end(cub->data->mlx);
	else if (code == CAMERA_LEFT)
		cub->keys.cam_left = true;
	else if (code == CAMERA_RIGHT)
		cub->keys.cam_right = true;
	else if (code == KEY_STRAIGHT)
		cub->keys.key_straight = true;
	else if (code == KEY_LEFT)
		cub->keys.key_left = true;
	else if (code == KEY_BACK)
		cub->keys.key_back = true;
	else if (code == KEY_RIGHT)
		cub->keys.key_right = true;
	else if (code == KEY_M && cub->keys.key_map == true)
		cub->keys.key_map = false;
	else if (code == KEY_M && cub->keys.key_map == false)
		cub->keys.key_map = true;
	return (0);
}

int	key_realease(int code, t_cub *cub)
{
	if (code == CAMERA_LEFT)
		cub->keys.cam_left = false;
	else if (code == CAMERA_RIGHT)
		cub->keys.cam_right = false;
	else if (code == KEY_STRAIGHT)
		cub->keys.key_straight = false;
	else if (code == KEY_LEFT)
		cub->keys.key_left = false;
	else if (code == KEY_BACK)
		cub->keys.key_back = false;
	else if (code == KEY_RIGHT)
		cub->keys.key_right = false;
	return (0);
}

int	close_window(t_cub *cub)
{
	mlx_loop_end(cub->data->mlx);
	return (0);
}

void	key_init(t_cub *cub)
{
	mlx_hook(cub->data->win, KeyPress, KEY_PRESS, &key_press, cub);
	mlx_hook(cub->data->win, KeyRelease, KEY_RELEASE_MASK, &key_realease, cub);
	mlx_hook(cub->data->win, DestroyNotify, KEY_DESTROY, &close_window, cub);
}
