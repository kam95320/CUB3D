/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:41:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/21 15:58:56 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	everyinit(t_cub *cub)
{
	cub->data = malloc(sizeof(t_data));
	if (!cub->data)
		wgas(cub, "error data init malloc\n", NULL);
	cub->cam = malloc(sizeof(t_cam));
	if (!cub->cam)
	{
		wgas(cub, "var cam =  not yet\n", NULL);
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
