/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:58:07 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/28 14:18:45 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../headers/utils.h"

int	main(int argc, char *argv[])
{
	t_minilib_window	mlx_data;
	two_d_t				two_d;

	// t_player			data_player;
	// t_info_texture		data_texture;
	check_arg_init_mlx(argc, argv, &mlx_data);
	if (true == take_mem_map(&mlx_data, &two_d, argv[1]))
	{
		close(mlx_data.map_data.fd);
	}
	if(map_is_valid(argv[1], &mlx_data) == false)
		return()
	player_data_initialization(&mlx_data.player_info);
	texture_data_initialization(&mlx_data.texture_info);
}
