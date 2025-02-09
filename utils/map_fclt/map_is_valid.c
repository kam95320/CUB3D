/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:16:58 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/09 19:30:16 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

bool	map_is_valid(char **mp, t_minilib_window *data_mlx)
{
	int	i;
	int	j;

	i = 0;
	printf("mp in map_is_good_print\n");
	printf("mp[i] =  %s\n", mp[i]);
	while (mp[i])
	{
		
		printf("pass in  map_valid 1 while tours =  %d\n", i);
		j = 0;
		while (mp[i][j])
		{
			printf("pass in  map_valid 2 while\n");
			skip_space(mp, i, j);
			is_good_print(&data_mlx->texture_info, mp, i, j);
		
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
