/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:51:11 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/20 14:09:08 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	*texture_convert(t_minilib_window *data, char *txt_ph)
{
	t_manip_img	m_img;
	int			*buff_pix;
	int			y;
	int			x;
	initialzation_txt(data, &m_img,  txt_ph);
	buff_pix = ft_calloc(1, sizeof(int) * (data->texture_info.texture_size
				* data->texture_info.texture_size));
	y = 0;
	while (y < data->texture_info.texture_size)
	{
		x = 0;
		while (x < data->texture_info.texture_size)
		{
			buff_pix[y * data->texture_info.texture_size
				+ x] = m_img.pixel_img[y * data->texture_info.texture_size + x];
			x += 1;
		}
		y += 1;
	}
	mlx_destroy_image(data->mlx_connex, m_img.ptr_img);
	return (buff_pix);
}
