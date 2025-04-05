/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:21:46 by tespandj          #+#    #+#             */
/*   Updated: 2025/04/04 11:07:50 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	looping(t_cub *cub)
{
	printf("\n-----looping deb-----\n");
	movement(cub);
	cub->ray->x = -1;
	while (++cub->ray->x < cub->data->width)
	{
		printf("pass in in  while looping deb\n ray->x =  %d\n", cub->ray->x);
		printf("compare to ray widht = %d\n", cub->data->width);
		dda(cub, cub->ray);
		raycast(cub, cub->ray);
		printf("\npass in in  while looping end\n");
	}
	printf("sort  to the  while loop\n");
	// minimap(cub, cub->map->matrix);
	// mlx_put_image_to_window(cub->data->mlx, cub->data->win, cub->data->img, 0,
	// 	0);
	printf("\n-----looping end-----\n");
	return (0);
}
int	cub3d(struct s_cub *cub)
{
	printf("\n-----cub3d deb-----\n");
	cub->txt[NO]->img = mlx_xpm_file_to_image(cub->data->mlx,
			cub->txt[NO]->name, &cub->txt[NO]->width, &cub->txt[NO]->height);
	printf("cub->data->mlx =  %p\n", cub->data->mlx);
	printf("cub->txt[NO]->name=  %p\n", cub->data->mlx);
	printf(" &cub->txt[NO]->width =  %d\n", cub->txt[NO]->width);
	printf("&cub->txt[NO]->height=  %d\n", cub->txt[NO]->height);
	printf("img[NO] =  %p\n", cub->txt[NO]->img);
	if (cub->txt[NO]->img)
		printf("fonctionne\n");
	else
		printf("marche pas\n");
	printf("\n-----cub3d middle-----\n");
	mlx_put_image_to_window(cub->data->mlx, cub->data->win, cub->txt[NO]->img,
		0, 0);
	mlx_hook(cub->data->win, KeyPress, 1L << 0, &press, cub);
	mlx_hook(cub->data->win, KeyRelease, 1L << 1, &release, cub);
	mlx_hook(cub->data->win, DestroyNotify, 0, &end_win, cub);
	mlx_loop_hook(cub->data->mlx, looping, cub);
	mlx_mouse_hide(cub->data->mlx, cub->data->win);
	mlx_loop(cub->data->mlx);
	printf("\n-----cub3d end-----\n");
	return (0);
}
