/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:16:58 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/15 18:38:55 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"


void	map_is_valid(char **mp, t_minilib_window *data_mlx)
{
	int i;
	int j;

	i = 0;
	while (mp[i])
	{
		j = 0;
		while (mp[i][j])
		{
            skip_space(mp, i, j);
			is_good_print(&data_mlx->texture_info,  mp,  i,  j);
			
		}
	}
}