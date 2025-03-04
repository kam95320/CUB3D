/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:14:13 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/04 14:03:18 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	init_direct(t_minilib_window *mlx_data)
{
	int	NORTH;
	int	SOUTH;
	int	EAST;
	int	WEST;

	NORTH = 0;
	SOUTH = 1;
	EAST = 2;
	WEST = 3;
	mlx_data->text[NORTH] = texture_convert(mlx_data,
			mlx_data->texture_info.direct_north);
	mlx_data->text[SOUTH] = texture_convert(mlx_data,
			mlx_data->texture_info.direct_south);
	mlx_data->text[EAST] = texture_convert(mlx_data,
			mlx_data->texture_info.direct_east);
	mlx_data->text[WEST] = texture_convert(mlx_data,
			mlx_data->texture_info.direct_west);
}
void	init_img_txt_textures(t_minilib_window *mlx_data)
{
	mlx_data->text = ft_calloc(5, sizeof(mlx_data->texture_info));
	init_direct(mlx_data);
}
