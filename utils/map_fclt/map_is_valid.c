/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:16:58 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/30 14:24:45 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

bool	map_is_valid(char **mp, t_minilib_window *data_mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mp[i])
	{
		j = 0;
		while (mp[i][j])
		{
			skip_space(mp, i, j);
			if (!is_good_print(&data_mlx->texture_info, mp, i, j))
			{
				free_txt(&data_mlx->texture_info);
				return (false);
			}
			j++;
		}
		i++;
	}
	if (vrb_txt_valid(&data_mlx->texture_info) == false)
	{
		free_txt(&data_mlx->texture_info);
		return (false);
	}
	return (true);
}
