/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:16:27 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/17 13:53:02 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

// void	render_ceiling(t_minilib_window *data)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < WD_SIZE_HEIGHT / 2)
// 	{
//         x = 0;
// 		while (x < WD_SIZE_WIDTH)
// 		{
// 			mlx_pixel_put(data->mlx_connex, data->img.ptr_img, x, y,
// 				data->texture_info.hxd_ceiling);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	render_floor(t_minilib_window *data)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < WD_SIZE_HEIGHT / 2)
// 	{
//         x = 0;
// 		while (x < WD_SIZE_WIDTH && y < WD_SIZE_HEIGHT)
// 		{
// 			mlx_pixel_put(data->mlx_connex, data->img.ptr_img, x, y,
// 				data->texture_info.hxd_floor);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_square(t_minilib_window *data, int x, int y, int color)
// {
//     printf(" pass in draw_square deb\n");
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < TI
// LE_SIZE)
// // 	{
// //         j = 0;
// //         printf("pass in while (i < TI
// LE_SIZE) = %d\n ", i);
// // // 		while (j < TI
// // LE_SIZE)
// // // 		{
// // //             printf("(j < TI
// LE_SIZE) =  %d\n", j);
// // 			mlx_pixel_put(data->mlx_connex, data->img.ptr_img, x + j, y + i,
// // 				color);
// //                 j ++;
// // 		}
// // 		i++;
// // 	}
// //         printf(" pass in draw_square end\n");

// // }

// // void	render_wall(t_minilib_window *data, char **map)
// // {
// //     printf("reder_wall deb\n");
// // 	int	y;
// // 	int	x;

// // 	y = 0;
// // 	while (map[y])
// // 	{
// //         printf("pass in while map[y] =  %d\n", y);
// // 		x = 0;
// // 		while (map[y][x])
// // 		{
// //             printf("pass in while map[y][x] =  %d\n", x);

// // 			if (map[y][x] == '1')
// // 			{
// //                 printf("pass in if(map[y][x] == '1' =  %d",  x);
// // 				draw_square(data, x * TI
// LE_SIZE, y * TILE_SIZE, COLOR_WALL);
// // 			}
// // 			else if (map[y][x] == '0' || map[y][x] == 'N')
// // 				draw_square(data, x * TI
// // LE_SIZE, y * TI
// // LE_SIZE,
// // 					data->texture_info.hxd_floor);
// // 			x++;
// // 		}
// // 		y++;
// // 	}
// //     printf("render_wall deb end\b");
// // }

void	render_ceiling(t_minilib_window *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WD_SIZE_HEIGHT / 2)
	{
		x = 0; // Remettre x à 0 pour chaque ligne
		while (x < WD_SIZE_WIDTH)
		{
			mlx_pixel_put(data->mlx_connex, data->window, x, y,
				data->texture_info.hxd_ceiling);
			x++;
		}
		y++;
	}
}

void	render_floor(t_minilib_window *data)
{
	int	x;
	int	y;

	y = WD_SIZE_HEIGHT / 2;
	while (y < WD_SIZE_HEIGHT)
	{
		x = 0;
		while (x < WD_SIZE_WIDTH)
		{
			mlx_pixel_put(data->mlx_connex, data->window, x, y,
				data->texture_info.hxd_floor);
			x++;
		}
		y++;
	}
}

static void	msg_debug(t_minilib_window *data, int x, int j, int y, int i,
		int color)
{
	int	var_x_j;
	int	var_y_i;

	var_x_j = x + j;
	var_y_i = y + i;
	printf("data->mlx_connex =  %p\n", data->mlx_connex);
	printf("data->img.ptr_img =  %p\n", data->img.ptr_img);
	printf(" x + j  = %d\n", var_x_j);
	printf(" y + i  = %d\n", var_y_i);
	printf("color = %d\n", color);
	printf("data->window = %p\n", data->window);
}
void	draw_square(t_minilib_window *data, int x, int y, int color)
{
	int	i;
	int	j;

	printf("pass in draw_square deb\n");
	printf("data->img.ptr_img is  %p\n", data->img.ptr_img);
	(void)color;
	if (!data->img.ptr_img)
	{
		printf("ERROR: data->img.ptr_img is NULL\n");
		return ;
	}
	if (!data->window)
	{
		printf("ERROR: data->win is NULL!\n");
		return ;
	}
	i = 0;
	j = 0;
	printf("TILE_SIZE = %d\n", TILE_SIZE);
	while (i < TILE_SIZE)
	{
		if (y + i >= WD_SIZE_HEIGHT)
		{
			printf("OUT OF BOUNDS (y): y+i=%d (limit=%d)\n", y + i,
				WD_SIZE_HEIGHT);
			break ;
		}
		j = 0;
		while (j < TILE_SIZE)
		{
			if (x + j >= WD_SIZE_WIDTH)
			{
				printf("OUT OF BOUNDS (x): x+j=%d (limit=%d)\n", x + j,
					WD_SIZE_WIDTH);
				break ;
			}
			printf("Drawing: x=%d, y=%d, TILE_SIZE=%d\n", x, y, TILE_SIZE);
			// 🛠 Vérification finale AVANT d'afficher
			if ((x + j < WD_SIZE_WIDTH) && (y + i < WD_SIZE_HEIGHT))
			{
				msg_debug(data, x, j, y, i, color);
				mlx_pixel_put(data->mlx_connex, data->window, x + j, y + i,
					color);
			}
			j++;
		}
		i++;
	}
	printf("pass in draw_square end\n");
}

void	render_map(t_minilib_window *data, char **map)
{
	int	y;
	int	x;
	int	offset_x;
	int	offset_y;

	offset_x = (WD_SIZE_WIDTH - (data->map_data.map_width * TILE_SIZE)) / 2;
	offset_y = (WD_SIZE_HEIGHT - (map_height * TILE_SIZE)) / 2;
	printf("render_wall deb\n");
	y = 0;
	while (map[y])
	{
		if (map[y] == NULL)
			break ; // Protection contre les NULL
		printf("pass in while map[y] =  %d\n", y);
		x = 0;
		printf("Rendering: map[%d][%d] = %c\n", y, x, map[y][x]);
		while (map[y][x])
		{
			printf("pass in while map[y][x] =  %d\n", x);
			if (map[y][x] == '1')
			{
				printf("pass in if(map[y][x] == '1'\n) =  %d", x);
				draw_square(data, x * TILE_SIZE, y * TILE_SIZE, COLOR_WALL);
			}
			else if (map[y][x] == '0' || map[y][x] == 'N')
			{
				draw_square(data, x * TILE_SIZE, y * TILE_SIZE,
					data->texture_info.hxd_floor);
			}
			x++;
		}
		y++;
	}
	printf("render_wall end\n");
}
