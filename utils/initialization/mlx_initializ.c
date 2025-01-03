/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initializ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:04:43 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/03 16:23:46 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	mlx_initializ(t_minilib_window *mlx_data)
{
	mlx_data->mlx_connex = mlx_init();
	if (!mlx_data->mlx_connex)
	{
		print_error("probleme with mlx initializtio\n");
		exit(1);
	}
	mlx_data->window = mlx_new_window(mlx_data->mlx_connex, WD_SIZE_WIDTH,
			WD_WIN_HEIGHT, "CUB3D");
	if (!mlx_data->window)
	{
		print_error("probleme with mlx window\n");
		exit(1);
	}
}
