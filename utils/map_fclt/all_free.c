/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:49:22 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/05 14:21:07 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

// void	free_img(t_manip_img *img)
// {
// 	if (img)
// 	{
// 		free(img->ptr_img);
// 		img->ptr_img = NULL;
// 		free(img->pixel_img);
// 		img->pixel_img = NULL;
// 	}
// }

// void	free_mlx(t_minilib_window *data)
// {
// 	if (data)
// 	{
// 		free(data->mlx_connex);
// 		data->mlx_connex = NULL;
// 		free(data->window);
// 		data->window = NULL;
// 		if (data->img.pix_mem_texture)
// 		{
// 			free_tab((void **)data->img.pix_mem_texture);
// 			data->img.pix_mem_texture = NULL;
// 		}
// 		if (data->text)
// 		{
// 			free_tab((void **)data->text);
// 			data->text = NULL;
// 		}
// 	}
// }

// // void	free_mlx(t_cub *cub)
// // {
// // 	if (!cub)
// // 		return ;
// // 	if (cub->mlx_connex)
// // 		free(cub->mlx_connex);
// // 	cub->mlx_connex = NULL;
// // 	if (cub->window)
// // 		free(cub->window);
// // 	cub->window = NULL;
// // 	free_pix_mem_texture(cub);
// // 	free_textures(cub);
// // }

// static void	free_pix_mem_texture(t_cub *cub)
// {
// 	if (cub->img.pix_mem_texture)
// 	{
// 		if (cub->img.pix_mem_texture[0])
// 			free(cub->img.pix_mem_texture[0]);
// 		if (cub->img.pix_mem_texture[1])
// 			free(cub->img.pix_mem_texture[1]);
// 		if (cub->img.pix_mem_texture[2])
// 			free(cub->img.pix_mem_texture[2]);
// 		if (cub->img.pix_mem_texture[3])
// 			free(cub->img.pix_mem_texture[3]);
// 		free(cub->img.pix_mem_texture);
// 		cub->img.pix_mem_texture = NULL;
// 	}
// }


// void	free_mp(t_map *map_data)
// {
// 	if (map_data)
// 	{
// 		free(map_data->path);
// 		map_data->path = NULL;
// 		free_tab((void **)map_data->file);
// 		map_data->file = NULL;
// 	}
// }

// void  all_free(t_minilib_window *data)
// {
// 	if(data->text)
// 			free_tab((void **)data -> text);
// 	if(data->img.pix_mem_texture)
// 			free_tab((void **)data->img.pix_mem_texture);
// 	free_txt(&data->texture_info);
// 	free_mp(&data->map_data);
// }


void	free_textures(t_txt **txt)
{
	if (txt[0])
		free(txt[0]);
	if (txt[1])
		free(txt[1]);
	if (txt[2])
		free(txt[2]);
	if (txt[3])
		free(txt[3]);
}

static void	free_data_struct(t_data *data)
{
	if (!data)
		return ;
	if (data->mlx)
		free(data->mlx);
	if (data->win)
		free(data->win);
	if (data->img)
		free(data->img);
	free(data);
}

void	free_mlx(t_cub *cub)
{
	if (!cub)
		return ;
	free_textures(cub->txt);
	free_data_struct(cub->data);
	cub->data = NULL;
}