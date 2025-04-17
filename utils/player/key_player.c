/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:06:56 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/17 16:47:17 by kahoumou         ###   ########.fr       */
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
	else if (code == KEY_UP)
		cub->keys.key_up = true;
	else if (code == KEY_LEFT)
		cub->keys.key_left = true;
	else if (code == KEY_DOWN)
		cub->keys.key_down = true;
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
	else if (code == KEY_UP)
		cub->keys.key_up = false;
	else if (code == KEY_LEFT)
		cub->keys.key_left = false;
	else if (code == KEY_DOWN)
		cub->keys.key_down = false;
	else if (code == KEY_RIGHT)
		cub->keys.key_right = false;
	return (0);
}
int	close_window(t_cub *cub)
{
	printf("window is close\n");
	mlx_loop_end(cub->data->mlx);
	return (0);
}

void	key_init(t_cub *cub)
{
	printf("\n-----key_init pass deb-----\n");
	mlx_hook(cub->data->win, KeyPress, KEY_PRESS, &key_press, cub);
	mlx_hook(cub->data->win, KeyRelease, KEY_RELEASE_MASK, &key_realease, cub);
	mlx_hook(cub->data->win, DestroyNotify, KEY_DESTROY, &close_window, cub);
	printf("\n-----key_init pass end-----\n");
}