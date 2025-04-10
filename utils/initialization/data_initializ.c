/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:51:17 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/14 13:54:24 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	data_initializ(t_minilib_window *mlx_data)
{
	mlx_data->mlx_connex = NULL;
	mlx_data->window = NULL;
	mlx_data->size_weight = WD_SIZE_HEIGHT;
	mlx_data->size_width = WD_SIZE_WIDTH;
	mlx_data->img.pix_mem_texture = NULL;
	mlx_data->text = NULL;
}
