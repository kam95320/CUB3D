/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:21:46 by tespandj          #+#    #+#             */
/*   Updated: 2025/03/26 19:06:39 by kahoumou         ###   ########.fr       */
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

void	free_map(t_cub *cub)
{
	if (cub->map)
	{
		if (cub->map->NO)
			free(cub->map->NO);
		if (cub->map->SO)
			free(cub->map->SO);
		if (cub->map->EA)
			free(cub->map->EA);
		if (cub->map->WE)
			free(cub->map->WE);
		if (cub->map->floor)
			free(cub->map->floor);
		if (cub->map->ceiling)
			free(cub->map->ceiling);
		if (cub->map->matrix)
			fsplit(cub->map->matrix);
	}
	if (cub->fd > 0)
		gnl_free(cub->fd);
	free(cub->map);
}
void	freend(t_cub *cub)
{
	free_map(cub);
	if (cub->map_name)
		free(cub->map_name);
	if (cub->data)
		free(cub->data);
	if (cub->cam)
		free(cub->cam);
	if (cub->ray)
		free(cub->ray);
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
	// freend(cub);
	return (0);
}
