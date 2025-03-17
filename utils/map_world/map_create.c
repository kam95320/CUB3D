/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:45:13 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/17 14:04:11 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	map_create(t_minilib_window *data, char **map)
{
	render_map(data, map);
	// render_ceiling(data);
	// render_floor(data);
}