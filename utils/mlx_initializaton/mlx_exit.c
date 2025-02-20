/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:17:21 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/20 17:21:10 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	mlx_exit(t_minilib_window *data)
{
	if (!data)
		exit(0);
	if (data->window && data->mlx_connex)
		mlx_destroy_window(data->mlx_connex, data->window);
	if (data->mlx_connex)
	{
		mlx_destroy_display(data->mlx_connex);
		mlx_loop_end(data->mlx_connex);
		free(data->mlx_connex);
	}
	exit(0);
}