/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:10:02 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/12 19:17:14 by kahoumou         ###   ########.fr       */
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
			if (map[j][i] == 'N')
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
			if (dir_is_find(cub, map[j][i]) == true)
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
	int		x;
	int		y;

	x = cub->player->orig_pl_x;
	y = cub->player->orig_pl_y;
	deg = cub->player->fov_deg = 66.0;
	cub->player->fov_rad = deg * M_PI / 180.0;
	fov_rad = cub->player->fov_rad;
	cub->player->player_vw_lenght = tan(fov_rad / 2.0);
	cub->player->fl_pl_pos_y = x + 0.5;
	cub->player->fl_pl_pos_x = x + 0.5;
}
void	init_player(t_cub *cub)
{
	get_player_pos(cub);
	init_player_calc(cub);
	double pl_lenght = cub->player->player_vw_lenght;
	if (cub->player->dir == 'N')
	{
		cub->player->cam_pos_x = 0.0;
		cub->player->cam_pos_y = -1.0;
		cub->ray->plane.x = pl_lenght;
		cub->ray->plane.y = 0.0;
	}
	else if (cub->player->dir == 'S')
	{
		cub->player->cam_pos_x = 0.0;
		cub->player->cam_pos_y = 1.0;
		cub->ray->plane.x = -pl_lenght;
		cub->ray->plane.y = 0.0;
	}
	else if (cub->player->dir == 'E')
	{
		cub->player->cam_pos_x = 1.0;
		cub->player->cam_pos_y = 0.0;
		cub->ray->plane.x = 0.0;
		cub->ray->plane.y = pl_lenght;
	}
	else if (cub->player->dir == 'W')
	{
		cub->player->cam_pos_x = -1.0;
		cub->player->cam_pos_y = 0.0;
		cub->ray->plane.x = 0.0;
		cub->ray->plane.y = -pl_lenght;
	}
}