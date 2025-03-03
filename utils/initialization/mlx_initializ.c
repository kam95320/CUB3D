/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initializ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:04:43 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/27 12:29:57 by kahoumou         ###   ########.fr       */
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
}
