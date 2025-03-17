/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:33:15 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/13 18:18:10 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	print_texture_info(t_info_texture *texture)
{
	if (!texture)
		return ;
	printf("\nTexture Information:\n");
	printf("--------------------\n");
	printf("Direct North: %s\n", texture->direct_north);
	printf("Direct South: %s\n", texture->direct_south);
	printf("Direct West:  %s\n", texture->direct_west);
	printf("Direct East:  %s\n\n", texture->direct_east);
	printf("Hex Floor:    0x%lX\n", texture->hxd_floor);
	printf("Hex Ceiling:  0x%lX\n\n", texture->hxd_ceiling);
	if (texture->floor)
		printf("Floor Color (RGB):   %d\n", *texture->floor);
	else
		printf("Floor Color (RGB):   NULL\n");
	if (texture->ceiling)
		printf("Ceiling Color (RGB): %d\n\n", *texture->ceiling);
	else
		printf("Ceiling Color (RGB): NULL\n");
	printf("Texture Size: %d\n", texture->texture_size);
	printf("Step by Step: %.6f\n", texture->step_by_step);
	printf("Position:     %.6f\n\n", texture->position);
	printf("X: %d, Y: %d\n", texture->x, texture->y);
	printf("Red:   %d\n", texture->red);
	printf("Green: %d\n", texture->green);
	printf("Blue:  %d\n\n", texture->blue);
}

#include <stdio.h>

void	print_minilib_window_info(t_minilib_window *window)
{
	if (!window)
		return ;
	printf("\nMinilibX Window Information:\n");
	printf("----------------------------\n");
	printf("MLX Connection: %p\n", window->mlx_connex);
	printf("Window Pointer: %p\n", window->window);
	printf("Size Weight: %d\n", window->size_weight);
	printf("Size Width:  %d\n\n", window->size_width);
	printf("Text Pointer: %p\n\n", window->text);
	printf("\n----------------------------\n");
}

void	print_map_info(t_map *map)
{
	if (!map)
		return ;
	printf("\nMap Information:\n");
	printf("----------------\n");
	printf("Path: %s\n", map->path ? map->path : "NULL");
	printf("File Pointer: %p\n", map->file);
	printf("File Descriptor: %d\n", map->fd);
	printf("Line Length: %d\n", map->line_len);
	printf("Height: %d\n", map->height);
	printf("Width: %d\n", map->width);
	printf("Map Ending: %d\n", map->map_ending);
	printf("Zoom: %d\n", map->zoom);
}

void	print_two_d_info(two_d_t *two_d)
{
	if (!two_d)
		return ;
	printf("\nTwo-Dimensional Structure Information:\n");
	printf("--------------------------------------\n");
	printf("Row: %d\n", two_d->row);
	printf("Index (i): %d\n", two_d->i);
	printf("Line: %s\n", two_d->line ? two_d->line : "NULL");
	printf("Column: %zu\n", two_d->col);
}

void	print_manip_img_info(t_manip_img *img)
{
	if (!img)
		return ;
	printf("\nImage Manipulation Information:\n");
	printf("-------------------------------\n");
	printf("Image Pointer: %p\n", img->ptr_img);
	printf("Pixel Image Pointer: %p\n", img->pixel_img);
	printf("Pixel Image Value: %d\n", img->pix_img);
	printf("Pixel Memory Texture Pointer: %p\n", img->pix_mem_texture);
	printf("Size of Line: %d\n", img->size_of_line);
	printf("Oct Indian: %d\n", img->oct_indian);
}
void	size_is_valide(t_manip_img *img, t_minilib_window *data)
{
	printf("----------text size validity----------\n");
	printf("Taille des textures -> Hauteur: %d, Largeur: %d\n",
		data->size_weight, data->size_width);
	printf("Test : écriture et lecture de la mémoire allouée...\n");
	for (int i = 0; i < data->size_weight; i++)
	{
		for (int j = 0; j < data->size_width; j++)
		{
			img->pix_mem_texture[i][j] = (i * j) % 255;
			// Écriture d'une valeur
			if (img->pix_mem_texture[i][j] != (i * j) % 255)
			// Lecture et vérification
			{
				printf("ERREUR de lecture à [%d][%d]!\n", i, j);
			}
		}
	}
	printf("✅ Accès mémoire réussi, pas d'erreur d'écriture/lecture !\n");
	printf("pass in initialization_texture\n");
}


void print_player_info(t_player *player)
{
    if (!player)
        return ;

    printf("\nPlayer Information:\n");
    printf("--------------------\n");

    printf("Direction: %c\n", player->direction);
    printf("Rotation: %d\n", player->rotation);
    printf("Player Move: %d\n\n", player->player_move);

    printf("Floating Player Position (X, Y): (%.6f, %.6f)\n",
	player->fl_pl_pos_x, player->fl_pl_pos_y);
    printf("Camera Position (X, Y): (%.6f, %.6f)\n\n", player->cam_pos_x,
	player->cam_pos_y);

    printf("Gesture (X, Y): (%d, %d)\n\n", player->gesture_x,
	player->gesture_y);
}

void	test_put_img(t_minilib_window *mlx_data)
{
	int	i;

	printf("📌 Vérification des pixels chargés :\n");
	for (i = 0; i < 10; i++)
		printf("Pixel %d : %X\n", i, mlx_data->img.pixel_img[i]);
	for (int y = 200; y < 280; y++)
	{
		for (int x = 220; x < 300; x++)
		{
			mlx_pixel_put(mlx_data->mlx_connex, mlx_data->window, x, y,
				0xFFFFFF);
		}
	}
}





