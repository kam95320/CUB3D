/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:28:37 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/14 16:52:34 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	ray_loop(t_cub *cub)
{
	int x;
	x = 0;
	while (x < cub->data->width)
	{
		cast_single_ray(cub, x);
		draw_vertical_line(cub, x);
	}
}