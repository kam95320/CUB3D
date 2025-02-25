/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialzation_txt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:12:16 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/25 14:41:16 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"
#include <ctype.h>
#include <string.h>

void	restart_img(t_manip_img *img)
{
	printf("deb restart_img\n");
	img->ptr_img = NULL;
	img->pixel_img = NULL;
	img->pix_img = 0;
	img->size_of_line = 0;
	img->oct_indian = 0;
	printf("end restart_img\n");
}
static char	*end_line_spc(char *str)
{
	int	i;

	
	 i = ft_strlen(str) - 1;
	while (str[i])
	{
		printf("pass\n");
		
		if ((str[i] >= 7 && str[i] <= 13) || str[i] == 32)
		{
			str[i] = '\0';
		}
		i--;
	}
	return(str);
}

void	initialzation_txt(t_minilib_window *data, t_manip_img *m_img,
		char *txt_ph)
{
	restart_img(m_img);
	txt_ph =  end_line_spc(txt_ph);
	if (isspace(txt_ph[strlen(txt_ph) - 1]))
	{
		printf("Erreur : Le chemin contient un espace en trop.\n");
	}

	m_img->ptr_img = mlx_xpm_file_to_image(data->mlx_connex, txt_ph,
			&data->texture_info.texture_size, &data->texture_info.texture_size);
	if (m_img->ptr_img == NULL)
	{
		print_error("problem with ptr_img\n");
		mlx_exit(data);
	}
	m_img->pixel_img = (int *)mlx_get_data_addr(m_img->ptr_img, &m_img->pix_img,
			&m_img->size_of_line, &m_img->oct_indian);
	printf("end initialzation_txt\n");
}