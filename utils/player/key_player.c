/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:06:56 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/15 11:33:08 by kahoumou         ###   ########.fr       */
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

void	key_init(t_cub *cub)
{
	mlx_hook(cub->data->addr, 2, KEY_PRESS, &key_press, &cub->keys);
	mlx_hook(cub->data->addr, 2, KEY_PRESS, &key_press, &cub->keys);
}