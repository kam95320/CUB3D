/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidge_of_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:09:56 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/26 18:51:02 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"


void bridge_of_structure(t_map_data *dest, t_minilib_window *win)
{
	convert_map_data(dest, win);
}

void convert_map_data(t_map_data *dest, t_minilib_window *win)
{
	dest->matrix = win->map_data.file;
	dest->L = win->map_data.height;
	dest->l = win->map_data.width;
	dest->NO = win->texture_info.direct_north;
	dest->SO = win->texture_info.direct_south;
	dest->WE = win->texture_info.direct_west;
	dest->EA = win->texture_info.direct_east;

	dest->floor = malloc(sizeof(t_rgb));
	dest->floor->r = win->texture_info.floor[0];
	dest->floor->g = win->texture_info.floor[1];
	dest->floor->b = win->texture_info.floor[2];

	dest->ceiling = malloc(sizeof(t_rgb));
	dest->ceiling->r = win->texture_info.ceiling[0];
	dest->ceiling->g = win->texture_info.ceiling[1];
	dest->ceiling->b = win->texture_info.ceiling[2];
}



