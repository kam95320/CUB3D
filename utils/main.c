/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:58:07 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/30 18:32:09 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../headers/free.h"
#include "../headers/utils.h"

int	main(int argc, char *argv[])
{
	static t_cub	cub = {0};
	two_d_t			two_d;

	check_arg_init_mlx(argc, argv, &cub);
	if (take_mem_map(&cub, &two_d, argv[1]))
		close(cub.fd);
	if (false == map_is_valid(&cub))
	{
		print_error(RED "MAP ERROR VALIDITY\n" RESET);
		free_mlx(&cub);
		return (0);
	}
	else
	{
		everyinit(&cub);
		if (!raycast(&cub))
		{
			free_mlx(&cub);
			return (0);
		}
		// all_debug(&cub);
		mlx_loop(cub.data->mlx);
		mlx_destroy_display(cub.data->mlx);
		free(cub.data->mlx);
	}
}
