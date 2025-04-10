/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:58:07 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/10 16:01:53 by kahoumou         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	static t_cub	cub = {0};
	two_d_t			two_d;
	t_txt			txt;
	t_player		player;

	check_arg_init_mlx(argc, argv, &cub);
	if (take_mem_map(&cub, &two_d, argv[1]))
		close(cub.fd);
	if (false == map_is_valid(&cub))
	{
		print_error("map error validity\n");
		free_mlx(&cub);
		return (0);
	}
	else
	{
		all_debug(&cub, &txt);
		everyinit(&cub);
		debug_raycasting(cub.ray);
		debug_player(&player);

	}
}
