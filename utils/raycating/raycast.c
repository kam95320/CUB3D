/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:10:51 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/27 14:14:10 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	write_map(char **map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map[y])
	{
		i = 0;
		if ((map[y][i] == '0' || map[y][i] == '1') && (map[y][i + 1] == '0'
				|| map[y][i + 1] == '1' || map[i][y + 1] == '\n' || map[i][y
				+ 1] == '\0'))
		{
			while (map[y][i])
			{
				if (map[y][i] == '0')
					printf(GREEN "%c" RESET, map[y][i]);
				else  if (map[y][i] == '1')
					printf(RED "%c" RESET, map[y][i]);
				else
					printf("%c", map[y][i]);
				i++;
			}
		}
		y++;
	}
}

bool	raycast(t_cub *cub)
{
	key_init(cub);
	if (!init_player(cub))
	{
		write_map(cub->map->matrix);
		printf(PURPLE "DIRECTION" RESET);
		printf(YELLOW "(N, S, W, E, O)\n" RESET);
		printf(RED "[PLAYER NOT FOUND]\n" RESET);
		return (false);
	}
	mlx_loop_hook(cub->data->mlx, ray_loop, cub);
	return (true);
}

