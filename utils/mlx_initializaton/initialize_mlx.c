/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:36:18 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/03 14:35:57 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	initialzation_mlx(t_minilib_window *data)
{
	data->mlx_connex = mlx_init();
	if (!data->mlx_connex)
		print_error("mlx initializtion error\n");
	data->window = mlx_new_window(data->mlx_connex, WD_SIZE_WIDTH,
			WD_WIN_HEIGHT, "cub3D");
	if (!data->window)
	{
		print_error("mlx new_window error\n");
		return ;
	}
}