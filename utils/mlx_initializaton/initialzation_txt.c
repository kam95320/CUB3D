/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialzation_txt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:12:16 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/20 16:54:23 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	restart_img(t_manip_img *img)
{
	img->ptr_img = NULL;
	img->pixel_img = NULL;
	img->pix_img = 0;
	img->size_of_line = 0;
	img->oct_indian = 0;
}

void	initialzation_txt(t_minilib_window *data, t_manip_img *m_img,
		char *txt_ph)
{
	restart_img(m_img);
	m_img->ptr_img = mlx_xpm_file_to_image(data->mlx_connex, txt_ph,
			&data->texture_info.texture_size, &data->texture_info.texture_size);
	if (m_img->ptr_img == NULL)
		mlx_exit(data);
	m_img->pixel_img = (int *)mlx_get_data_addr(m_img->ptr_img, &m_img->pix_img,
			&m_img->size_of_line, &m_img->oct_indian);
	return ;
}