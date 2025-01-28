/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:16:58 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/28 14:03:29 by kahoumou         ###   ########.fr       */
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
				return (false);
			j++;
		}
		i++;
	}
	if (vrb_txt_valid(&data_mlx->texture_info) == false)
		return (false);
	return (true);
}
