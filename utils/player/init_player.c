/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:10:02 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/25 16:53:55 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

bool	dir_is_find(t_cub *cub, char dir)
{
	if (dir == 'N')
	{
		cub->player->dir = 'N';
		return (true);
	}
	else if (dir == 'S')
	{
		cub->player->dir = 'S';
		return (true);
	}
	else if (dir == 'E')
	{
		cub->player->dir = 'E';
		return (true);
	}
	else if (dir == 'W')
	{
		cub->player->dir = 'W';
		return (true);
	}
	return (false);
}

void	orig_pl_pos(t_cub *cub)
{
	int		j;
	int		i;
	char	**map;

	j = 0;
	i = 0;
	map = cub->map->matrix;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if ((map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'W'
					|| map[j][i] == 'E') && (map[j][i + 1] == '0' || map[j][i
					+ 1] == '1'))
			{
				cub->player->orig_pl_y = j;
				cub->player->orig_pl_x = i;
			}
			i++;
		}
		j++;
	}
}

bool	get_player_pos(t_cub *cub)
{
	int		j;
	int		i;
	char	**map;

	j = 0;
	i = 0;
	map = cub->map->matrix;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if ((map[j][i] == '0' || map[j][i] == '1') && dir_is_find(cub,
					map[j][i + 1]) == true)
			{
				orig_pl_pos(cub);
				return (true);
			}
			i++;
		}
		j++;
	}
	return (false);
}

void	init_player_calc(t_cub *cub)
{
	double	deg;
	double	fov_rad;

	cub->player->fov_deg = 90;
	deg = cub->player->fov_deg;
	cub->player->fov_rad = deg * M_PI / 190.0;
	fov_rad = cub->player->fov_rad;
	cub->player->player_vw_lenght = tan(fov_rad / 2.0);
	cub->player->fl_pl_pos_x = cub->player->orig_pl_x + 0.5;
	cub->player->fl_pl_pos_y = cub->player->orig_pl_y + 0.5;
}

void	init_player(t_cub *cub)
{
	if (!get_player_pos(cub))
		wgas(cub, RED "Player direction not found" RESET, NULL);
	get_player_pos(cub);
	init_player_calc(cub);
	// init_e_w()
	init_player_dir_cam(cub, cub->player->dir);
}
