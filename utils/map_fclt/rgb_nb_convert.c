/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_nb_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:33:45 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/22 14:21:47 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	rgb_nb_convert(t_cub *cub, char **rgb, char f_c)
{
	if (f_c == 'f')
	{
		cub->map->floor->r = ft_atoi(rgb[0]);
		cub->map->floor->g = ft_atoi(rgb[1]);
		cub->map->floor->b = ft_atoi(rgb[2]);
	}
	if (f_c == 'c')
	{
		cub->map->ceiling->r = ft_atoi(rgb[0]);
		cub->map->ceiling->g = ft_atoi(rgb[1]);
		cub->map->ceiling->b = ft_atoi(rgb[2]);
	}
}
