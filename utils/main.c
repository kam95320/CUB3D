/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:58:07 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/13 16:08:41 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../headers/utils.h"

int	main(int argc, char *argv[])
{
	t_minilib_window	mlx_data;
	t_player			data_player;
	t_info_texture		data_texture;
	two_d_t				two_d;

	check_arg_init_mlx(argc, argv, &mlx_data);
	if (true == take_mem_map(&mlx_data, &two_d, argv[1]))
	{
		close(&mlx_data.map_data);
	}
	// map_is_valid(argv[1], mlx_data);
	player_data_initialization(&data_player);
	texture_data_initialization(&data_texture);
}
