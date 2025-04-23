/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_init_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:57:17 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/23 16:01:18 by kahoumou         ###   ########.fr       */
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
/*
 check juste si  il y a au moin 2 argument
 et si  le  fichier est  bien  valide avec check_is_valid
 */