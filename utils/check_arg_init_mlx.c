/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_init_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:57:17 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/02 17:18:16 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utils.h"

void	check_arg_init_mlx(int argc, char *argv[], t_minilib_window *mlx_data)
{
	(void)argv;
	if (argc != 2)
	{
		print_error("error with  map\n");
		exit(1);
	}
    data_initializ(mlx_data);
    mlx_initializ(mlx_data);
}