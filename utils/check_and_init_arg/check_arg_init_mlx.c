/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_init_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:57:17 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/22 13:27:28 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	check_arg_init_mlx(int argc, char *argv[], t_cub *cub)
{
	(void)argv;
	(void)cub;
	if (argc != 2)
	{
		print_error("error with  map\n");
		exit(1);
	}
	check_is_valid(argv[1]);
}
