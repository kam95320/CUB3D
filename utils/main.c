/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:58:07 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/02 17:26:16 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utils.h"

int	main(int argc, char *argv[])
{
	t_minilib_window mlx_data;
	t_player data_player;
	t_info_texture data_texture;
	check_arg_init_mlx(argc, argv, &mlx_data);
	player_data_initialization(&data_player);
	texture_data_initialization(&data_texture);
}