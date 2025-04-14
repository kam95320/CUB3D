/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:41:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/14 16:58:24 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	txtinit(t_cub *cub)
{
	cub->txt[NO]->img = mlx_xpm_file_to_image(cub->data->mlx,
			cub->txt[NO]->name, &cub->txt[NO]->width, &cub->txt[NO]->height);
	if (!cub->txt[NO]->img)
		wgas(cub, "mlx_xpm_file_to_image", "north texture");
	cub->txt[SO]->img = mlx_xpm_file_to_image(cub->data->mlx,
			cub->txt[SO]->name, &cub->txt[SO]->width, &cub->txt[SO]->height);
	if (!cub->txt[SO]->img)
		wgas(cub, "mlx_xpm_file_to_image", "south texture");
	cub->txt[EA]->img = mlx_xpm_file_to_image(cub->data->mlx,
			cub->txt[EA]->name, &cub->txt[EA]->width, &cub->txt[EA]->height);
	if (!cub->txt[EA]->img)
		wgas(cub, "mlx_xpm_file_to_image", "east texture");
	cub->txt[WE]->img = mlx_xpm_file_to_image(cub->data->mlx,
			cub->txt[WE]->name, &cub->txt[WE]->width, &cub->txt[WE]->height);
	if (!cub->txt[WE]->img)
		wgas(cub, "mlx_xpm_file_to_image", "west texture");
}

void	caminit(t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	while (cub->map->matrix[++y])
	{
		x = -1;
		while (cub->map->matrix[y][++x])
		{
			if (cub->map->matrix[y][x] == 'N' || cub->map->matrix[y][x] == 'S'
				|| cub->map->matrix[y][x] == 'E'
				|| cub->map->matrix[y][x] == 'O')
			{
				cub->map->matrix[y][x] = '0';
				cub->cam->player_pos = (t_mgam2f){x + 0.5, y + 0.5};
				break ;
			}
		}
	}
	cub->cam->look = (t_mgam2f){1.0, 0.0};
	mlx_mouse_move(cub->data->mlx, cub->data->win, cub->data->width / 2,
		cub->data->height / 2);
	mlx_mouse_get_pos(cub->data->mlx, cub->data->win, &cub->cam->mouse_x,
		&cub->cam->mouse_y);
}
void	everyinit(t_cub *cub)
{
	if (!cub->cam)
	{
		printf("var cam =  not yet\n");
	}
	cub->fd = -1;
	cub->player = malloc(sizeof(t_player));
	if (!cub->player)
		wgas(cub, "error player struct\n", NULL);
	cub->cam = malloc(sizeof(t_cam));
	if (!cub->cam)
		wgas(cub, "malloc cam failed", NULL);
	cub->ray = malloc(sizeof(t_ray));
	if (!cub->ray)
		wgas(cub, "malloc ray failed", NULL);
	init_player(cub);
	datainit(cub);
	caminit(cub);
	rayinit(cub->ray);
	txtinit(cub);
}
