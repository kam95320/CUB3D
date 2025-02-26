/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:50:38 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/26 16:39:58 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"


// typedef struct s_map
// {
// 	char	*path;
// 	char	**file;
// 	int		fd;
// 	int		line_len;
// 	int		height;
// 	int		width;
// 	int		map_ending;

// }			t_map;


void	aff_map(t_minilib_window *cub)
{
	int x;
	int y;

	y = -1;
	while (cub->map_data.file[++y])
	{
		x = -1;
		while (cub->map_data.file[y][++x])
		{
			if (cub->map_data.file[y][x] == '1')
				setblock(cub, x, y, 0x001514);
			else if (cub->map_data.file[y][x] == '0')
				setblock(cub, x, y, 0xFFE1EA);
		}
	}
}