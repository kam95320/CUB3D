/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:49:22 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/20 17:18:07 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	free_img(t_manip_img *img)
{
	if (img)
	{
		free(img->ptr_img);
		img->ptr_img = NULL;
		free(img->pixel_img);
		img->pixel_img = NULL;
	}
}

void	free_mlx(t_minilib_window *data)
{
	if (data)
	{
		free(data->mlx_connex);
		data->mlx_connex = NULL;
		free(data->window);
		data->window = NULL;
		if (data->pix_mem_texture)
		{
			free_tab((void **)data->pix_mem_texture);
			data->pix_mem_texture = NULL;
		}
		if (data->text)
		{
			free_tab((void **)data->text);
			data->text = NULL;
		}
	}
}

void	free_txt(t_info_texture *texture_info)
{
	if (texture_info)
	{
		free(texture_info->direct_north);
		free(texture_info->direct_south);
		free(texture_info->direct_west);
		free(texture_info->direct_east);
		free((void **)texture_info->hxd_floor);
		free((void **)texture_info->hxd_ceiling);
		free(texture_info->floor);
		free(texture_info->ceiling);
	}
}

void	free_mp(t_map *map_data)
{
	if (map_data)
	{
		free(map_data->path);
		map_data->path = NULL;
		free_tab((void **)map_data->file);
		map_data->file = NULL;
	}
}

void  all_free(t_minilib_window *data)
{
	if(data->text)
			free_tab((void **)data -> text);
	if(data->pix_mem_texture)
			free_tab((void **)data->pix_mem_texture);
	free_txt(&data->texture_info);
	free_mp(&data->map_data);
}