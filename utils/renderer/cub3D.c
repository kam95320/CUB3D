/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:21:46 by tespandj          #+#    #+#             */
/*   Updated: 2025/03/26 18:25:02 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	looping(t_cub *cub)
{
	movement(cub);
	raycast(cub);
	return (0);
}
int	end_win(t_cub *cub)
{
	mlx_destroy_image(cub->data->mlx, cub->data->img);
	mlx_destroy_window(cub->data->mlx, cub->data->win);
	mlx_destroy_display(cub->data->mlx);
	free(cub->data->mlx);
	freend(cub);
	exit(0);
}
int	cub3d(struct s_cub *cub)
{
	mlx_hook(cub->data->win, KeyPress, 1L << 0, &press, cub);
	mlx_hook(cub->data->win, KeyRelease, 1L << 1, &release, cub);
	mlx_hook(cub->data->win, MotionNotify, PointerMotionMask, &mousemotion,
		cub);
	// mlx_hook(cub->data->win, MotionNotify, 1L << 6, &mousemotion, cub);
	// mlx_hook(cub->data->win, MotionNotify, 1L << 6, NULL, NULL);
	mlx_hook(cub->data->win, DestroyNotify, 0, &end_win, cub);
	mlx_loop_hook(cub->data->mlx, looping, cub);
	mlx_mouse_hide(cub->data->mlx, cub->data->win);
	mlx_loop(cub->data->mlx);
	freend(cub);
	return (0);
}
