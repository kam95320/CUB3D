/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:58:07 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/25 15:25:44 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../headers/free.h"
#include "../headers/utils.h"

int	main(int argc, char *argv[])
{
	static t_minilib_window	mlx_data = {0};
	two_d_t					two_d;

	printf("%s", argv[1]);	
	player_data_initialization(&mlx_data.player_info);
	texture_data_initialization(&mlx_data.texture_info);
	check_arg_init_mlx(argc, argv, &mlx_data);
	if (take_mem_map(&mlx_data, &two_d, argv[1]))
		close(mlx_data.map_data.fd);
	if (false == map_is_valid(mlx_data.map_data.file, &mlx_data))
	{
		free_mlx(&mlx_data);
		return (0);
	}
	init_var_pl_n_s(&mlx_data.player_info);
	init_var_pl_e_w(&mlx_data.player_info);
	initialzation_mlx(&mlx_data);
	init_img_txt_textures(&mlx_data);
	mlx_loop(mlx_data.mlx_connex);
	// mlx_loop_hook(mlx_data.mlx_connex, , &mlx_data);
	printf("pass end of main\n");
	return (0);
}
