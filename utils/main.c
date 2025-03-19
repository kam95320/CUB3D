/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:58:07 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/19 15:11:40 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../headers/free.h"
#include "../headers/utils.h"

void	mlx_ftclt(t_minilib_window mlx_data)
{
	mlx_loop(mlx_data.mlx_connex);
	// mlx_loop_hook(mlx_data.mlx_connex, , &mlx_data);
}
void	all_print_info(t_minilib_window mlx_data, two_d_t two_d)
{
	t_player player;
	print_minilib_window_info(&mlx_data);
	print_texture_info(&mlx_data.texture_info);
	print_map_info(&mlx_data.map_data);
	print_manip_img_info(&mlx_data.img);
	print_two_d_info(&two_d);
	print_player_info(&player);
	size_is_valide(&mlx_data.img, &mlx_data);
	// test_put_img(&mlx_data);
	// draw_map(&mlx_data);
	
}
int	main(int argc, char *argv[])
{
	static t_minilib_window	mlx_data = {0};
	two_d_t					two_d;
	t_player player;

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
	initialization_texture(&mlx_data.img, &mlx_data);
	all_print_info(mlx_data, two_d);
	map_create(&mlx_data, mlx_data.map_data.file);
	init_player(&player, mlx_data.map_data.file);
	mlx_ftclt(mlx_data);
	return (0);
}
