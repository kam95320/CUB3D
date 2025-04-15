/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:10:51 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/15 16:18:57 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	raycast(t_cub *cub)
{
	init_player(cub);
	key_init(cub);
	mlx_loop_hook(cub->data->mlx, ray_loop, &cub);
}