/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:10:51 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/17 16:09:51 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	raycast(t_cub *cub)
{
	printf("-----raycast deb------\n");
	init_player(cub);
	key_init(cub);
	mlx_loop_hook(cub->data->mlx, ray_loop, cub);
	printf("-----raycast end------\n");

}