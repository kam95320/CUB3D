/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:53:31 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/06 14:46:53 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	initialization_texture(t_manip_img *img, t_minilib_window *data)
{
	int	index;

	index = 0;
	if (img->pix_mem_texture)
	{
		free_img(img);
	}
	img->pix_mem_texture = ft_calloc(data->size_weight,
			sizeof(*img->pix_mem_texture));
	if (!img->pix_mem_texture)
	{
		print_error("img->pix_mem_texture free\n");
		free_img(img);
	}
	while (index < data->size_weight)
	{
		img->pix_mem_texture[index] = ft_calloc(data->size_width + 1,
				sizeof(int));
		if (!img->pix_mem_texture[index])
		{
			free_img(img);
			print_error("probleme with pix_mem_texture[index]\n");
		}
		index++;
	}
}
