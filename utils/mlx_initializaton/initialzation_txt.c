/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialzation_txt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:12:16 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/03 15:57:12 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"
#include <ctype.h>
#include <string.h>

void	restart_img(t_manip_img *img)
{
	img->ptr_img = NULL;
	img->pixel_img = NULL;
	img->pix_img = 0;
	img->size_of_line = 0;
	img->oct_indian = 0;
}
static char	*end_line_spc(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if ((str[i] >= 7 && str[i] <= 13) || str[i] == 32)
		{
			str[i] = '\0';
		}
		i--;
	}
	return (str);
}

// static void	Debug_path(char *txt_ph)
// {
// 	if (access(txt_ph, F_OK))
// 	{
// 		printf("good path F_OK\n");

// 	}
// 	else
// 	{
// 		printf("error path\n");
// 		return ;
// 	}
// 	if (access(txt_ph, R_OK))
// 	{
// 		printf("good path R_OK\n");

// 	}
// 	else
// 	{
// 		printf("error path\n");
// 		return ;
// 	}
// 	if (access(txt_ph, W_OK))
// 	{
// 		printf("good path W_OK\n");

// 	}
// 	else
// 	{
// 		printf("error path\n");
// 		return ;
// 	}
// 	if (access(txt_ph, X_OK))
// 	{
// 		printf("good path X_OK\n");

// 	}
// 	else
// 	{
// 		printf("error path\n");
// 		return ;
// 	}
// }
void	initialzation_txt(t_minilib_window *data, t_manip_img *m_img,
		char *txt_ph)
{
	// restart_img(m_img);
	txt_ph = end_line_spc(txt_ph);

	m_img->ptr_img = mlx_xpm_file_to_image(data->mlx_connex, txt_ph,
			&data->texture_info.texture_size, &data->texture_info.texture_size);
	printf("\n\n");
	printf("ptr->img in  function initialization = %p\n", (void *)m_img->ptr_img);
	if (m_img->ptr_img == NULL)
	{
		print_error("problem with ptr_img\n");
		mlx_exit(data);
	}
	m_img->pixel_img = (int *)mlx_get_data_addr(m_img->ptr_img, &m_img->pix_img,
			&m_img->size_of_line, &m_img->oct_indian);
}