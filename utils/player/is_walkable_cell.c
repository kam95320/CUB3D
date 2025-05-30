/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_walkable_cell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:40:55 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/30 18:07:13 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"


int  is_valid_coord(t_cub *cub, double x, double y)
{
    int mx;
    int my;

    mx = (int)x;
    my = (int)y;
    if (mx < 0)
        return (0);
    if (mx >= cub->data->line_length)
        return (0);
    if (my < 0)
        return (0);
    if (my >= cub->data->height)
        return (0);
    if (cub->map->matrix[my][mx] != '0')
        return (0);
    return (1);
}


int is_walkable_cell(t_cub *cub, double x, double y)
{
    double left;
    double right;
    double up;
    double down;

    left = x - PLAYER_RADIUS;
    right = x + PLAYER_RADIUS;
    up = y - PLAYER_RADIUS;
    down = y + PLAYER_RADIUS;
    	if (dir_is_find(cub, cub->map->matrix[(int)y][(int)x]))
		cub->map->matrix[(int)y][(int)x] = '0';
    if (!is_valid_coord(cub, left, up))
        return (0);
    if (!is_valid_coord(cub, right, up))
        return (0);
    if (!is_valid_coord(cub, left, down))
        return (0);
    if (!is_valid_coord(cub, right, down))
        return (0);
    return (1);
}


