/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnr_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:15:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/12 19:09:30 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	init_mnp(t_minilib_window *win, t_manip_img *image, int width,
		int height)
{
	restart_img(image);
	image->ptr_img = mlx_new_image(win->mlx_connex, width, height);
	if (image->ptr_img == NULL)
	{
		print_error("eror with ptr img\n");
		return;
	}
		
	image->pixel_img = (int *)mlx_get_data_addr(image->ptr_img, &image->pix_img,
			&image->size_of_line, &image->oct_indian);
}

char	**gnrt_mn_mp(t_minilib_window *data, t_minimap *mp)
{
	char	**map_memeory;
	int		y;

	y = 0;
	map_memeory = ft_calloc(mp->mini_mp_size + 1, sizeof *map_memeory);
	if (!map_memeory)
	{
		return (NULL);
	}
	y = 0;
	while (y < mp->mini_mp_size && y < data->map_data.height)
	{
		map_memeory[y] = mnp_l(data, y);
	}
}
