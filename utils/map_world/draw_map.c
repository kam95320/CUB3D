/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:16:27 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/17 15:11:21 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

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

// static void	msg_debug(t_minilib_window *data, int x, int j, int y, int i,
// 		int color)
// {
// 	int	var_x_j;
// 	int	var_y_i;

// 	var_x_j = x + j;
// 	var_y_i = y + i;
// 	printf("data->mlx_connex =  %p\n", data->mlx_connex);
// 	printf("data->img.ptr_img =  %p\n", data->img.ptr_img);
// 	printf(" x + j  = %d\n", var_x_j);
// 	printf(" y + i  = %d\n", var_y_i);
// 	printf("color = %d\n", color);
// 	printf("data->window = %p\n", data->window);
// printf("TILE_SIZE = %d\n", TILE_SIZE);
// }
void	draw_square(t_minilib_window *data, int x, int y, int color)
{
	int	i;
	int	j;

	// printf("pass in draw_square deb\n");
	// printf("data->img.ptr_img is  %p\n", data->img.ptr_img);
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
	
	while (i < TILE_SIZE)
	{
		// if (y + i >= WD_SIZE_HEIGHT)
		// {
		// 	printf("OUT OF BOUNDS (y): y+i=%d (limit=%d)\n", y + i,
		// 		WD_SIZE_HEIGHT);
		// 	break ;
		// }
		j = 0;
		while (j < TILE_SIZE)
		{
			if (x + j >= WD_SIZE_WIDTH)
			{
				// printf("OUT OF BOUNDS (x): x+j=%d (limit=%d)\n", x + j,
					// WD_SIZE_WIDTH);
				break ;
			}
			// printf("Drawing: x=%d, y=%d, TILE_SIZE=%d\n", x, y, TILE_SIZE);
			if ((x + j < WD_SIZE_WIDTH) && (y + i < WD_SIZE_HEIGHT))
			{
				// msg_debug(data, x, j, y, i, color);
				mlx_pixel_put(data->mlx_connex, data->window, x + j, y + i,
					color);
			}
			j++;
		}
		i++;
	}
	// printf("pass in draw_square end\n");
}
void	render_map(t_minilib_window *data, char **map)
{
	int	y;
	int	x;
	int	map_width;
	int	map_height;
	int	offset_x;
	int	offset_y;
	int	screen_x;
	int	screen_y;

	map_width = 0;
	map_height = 0;
	while (map[0][map_width])
		map_width++;
	while (map[map_height])
		map_height++;
	offset_x = (WD_SIZE_WIDTH - (map_width * TILE_SIZE)) / 2;
	offset_y = (WD_SIZE_HEIGHT - (map_height * TILE_SIZE)) / 2;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y] && map[y][0] == '\0')
			y++;
		while (map[y][x])
		{
			if (!map[y] || !map[y][x])
				break ;
			if (map[y][x] == ' ')
				map[y][x] = '0';

			screen_x = offset_x + (x * TILE_SIZE);
			screen_y = offset_y + (y * TILE_SIZE);
			if (map[y][x] == '1')
				draw_square(data, screen_x, screen_y, COLOR_WALL);
			else if (map[y][x] == '0' || map[y][x] == 'N')
				draw_square(data, screen_x, screen_y,
					data->texture_info.hxd_floor);
			x++;
		}
		y++;
	}
}
