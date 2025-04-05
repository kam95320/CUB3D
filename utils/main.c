/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:58:07 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/04 09:58:36 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../headers/free.h"
#include "../headers/utils.h"

void	mlx_ftclt(t_minilib_window mlx_data)
{
	mlx_loop(mlx_data.mlx_connex);
	// mlx_loop_hook(mlx_data.mlx_connex, , &mlx_data);
}
// void	all_print_info(t_minilib_window mlx_data, two_d_t two_d, char **map)
// {
// 	(void)map;
// 	print_minilib_window_info(&mlx_data);
// 	print_texture_info(&mlx_data.texture_info);
// 	print_map_info(&mlx_data.map_data);
// 	print_manip_img_info(&mlx_data.img);
// 	print_two_d_info(&two_d);
// 	size_is_valide(&mlx_data.img, &mlx_data);
// }

void	datainit(t_cub *cub)
{
	printf("----datainit deb-----\n");
	cub->data = malloc(sizeof(t_data));
	if (cub->data == NULL)
		wgas(cub, "fail malloc cub->data", NULL);
	cub->data->width = 960;
	cub->data->height = 600;
	cub->data->mlx = mlx_init();
	mlx_get_screen_size(cub->data->mlx, &cub->data->width, &cub->data->height);
	cub->data->win = mlx_new_window(cub->data->mlx, cub->data->width,
			cub->data->height, "CUB bcp de D");
	if (!cub->data->win)
	{
		free(cub->data->mlx);
		wgas(cub, "Couldn't open the window", NULL);
	}
	cub->data->img = mlx_new_image(cub->data->mlx, cub->data->width,
			cub->data->height);
	printf("cub->data->img =  %p\n", cub->data->img);
	cub->data->addr = mlx_get_data_addr(cub->data->img,
			&cub->data->bits_per_pixel, &cub->data->line_length,
			&cub->data->endian);
	printf("----datainit end-----\n");
}

void	ciminit(t_cub *cub)
{
	int	x;
	int	y;

	printf("----ciminit deb-----\n");
	y = -1;
	while (cub->map->matrix[++y])
	{
		x = -1;
		while (cub->map->matrix[y][++x])
		{
			if (cub->map->matrix[y][x] == 'N' || cub->map->matrix[y][x] == 'S'
				|| cub->map->matrix[y][x] == 'E'
				|| cub->map->matrix[y][x] == 'O')
			{
				cub->map->matrix[y][x] = '0';
				cub->cam->player_pos = (t_mgam2f){x + 0.5, y + 0.5};
				break ;
			}
		}
	}
	cub->cam->look = (t_mgam2f){1.0, 0.0};
	mlx_mouse_move(cub->data->mlx, cub->data->win, cub->data->width / 2,
		cub->data->height / 2);
	mlx_mouse_get_pos(cub->data->mlx, cub->data->win, &cub->cam->mouse_x,
		&cub->cam->mouse_y);
	printf("----ciminit end-----\n");
}
void	rayinit(t_ray *ray)
{
	ray->x = 0;
	ray->map = (t_mgam2i){0, 0};
	ray->step = (t_mgam2i){-1, -1};
	ray->ray = (t_mgam2f){0.0, 0.0};
	ray->plane = (t_mgam2f){0.0, 0.66};
	ray->sidedist = (t_mgam2f){0.0, 0.0};
	ray->deltadist = (t_mgam2f){0.0, 0.0};
	ray->camerax = 0.0;
	ray->perpwalldist = 0.0;
	ray->whichside = 0;
}
void	debug_ptr(t_cub *cub)
{
	printf("--------- DEBUG PTRS ---------\n");
	printf("cub->txt = %p\n", cub->txt);
	printf("cub->txt[NO] =%s\n", cub->txt[NO]->name);
	printf("cub->txt[SO] =%s\n", cub->txt[SO]->name);
	printf("cub->txt[EA] =%s\n", cub->txt[EA]->name);
	printf("cub->txt[WE] =%s\n", cub->txt[WE]->name);
	printf("------------------------------\n");
	
}
void	txtinit(t_cub *cub)
{
	printf("\n----- txtinit deb -----\n");
	debug_ptr(cub);
	cub->txt[NO]->img = mlx_xpm_file_to_image(cub->data->mlx,
			cub->txt[NO]->name, &cub->txt[NO]->width, &cub->txt[NO]->height);
	if (!cub->txt[NO]->img)
		wgas(cub, "mlx_xpm_file_to_image", "north texture");
	cub->txt[SO]->img = mlx_xpm_file_to_image(cub->data->mlx,
			cub->txt[SO]->name, &cub->txt[SO]->width, &cub->txt[SO]->height);
	if (!cub->txt[SO]->img)
		wgas(cub, "mlx_xpm_file_to_image", "south texture");
	cub->txt[EA]->img = mlx_xpm_file_to_image(cub->data->mlx,
			cub->txt[EA]->name, &cub->txt[EA]->width, &cub->txt[EA]->height);
	if (!cub->txt[EA]->img)
		wgas(cub, "mlx_xpm_file_to_image", "east texture");
	cub->txt[WE]->img = mlx_xpm_file_to_image(cub->data->mlx,
			cub->txt[WE]->name, &cub->txt[WE]->width, &cub->txt[WE]->height);
	if (!cub->txt[WE]->img)
		wgas(cub, "mlx_xpm_file_to_image", "west texture");
	printf("\n----- txtinit end -----\n");
}

void	caminit(t_cub *cub)
{
	int	x;
	int	y;

	printf("\n----caminit deb----\n");
	y = -1;
	while (cub->map->matrix[++y])
	{
		x = -1;
		while (cub->map->matrix[y][++x])
		{
			if (cub->map->matrix[y][x] == 'N' || cub->map->matrix[y][x] == 'S'
				|| cub->map->matrix[y][x] == 'E'
				|| cub->map->matrix[y][x] == 'O')
			{
				cub->map->matrix[y][x] = '0';
				cub->cam->player_pos = (t_mgam2f){x + 0.5, y + 0.5};
				break ;
			}
		}
	}
	cub->cam->look = (t_mgam2f){1.0, 0.0};
	mlx_mouse_move(cub->data->mlx, cub->data->win, cub->data->width / 2,
		cub->data->height / 2);
	mlx_mouse_get_pos(cub->data->mlx, cub->data->win, &cub->cam->mouse_x,
		&cub->cam->mouse_y);
	printf("\n----caminit end----\n");
}
void	everyinit(t_cub *cub)
{
	printf("\n---everyinit----\n");
	if (!cub->cam)
	{
		printf("var cam =  not yet\n");
	}
	cub->fd = -1;
	datainit(cub);
	cub->cam = malloc(sizeof(t_cam));
	if (!cub->cam)
		wgas(cub, "malloc cam failed", NULL);
	caminit(cub);
	cub->ray = malloc(sizeof(t_ray));
	if (!cub->ray)
		wgas(cub, "malloc ray failed", NULL);
	rayinit(cub->ray);
	txtinit(cub);
	printf("everyinit whidht =  %d\n", cub->txt[NO]->width);
}

int	main(int argc, char *argv[])
{
	static t_cub	cub = {0};
	two_d_t			two_d;

	check_arg_init_mlx(argc, argv, &cub);
	if (take_mem_map(&cub, &two_d, argv[1]))
		close(cub.fd);
	if (false == map_is_valid(&cub))
	{
		print_error("map error validity\n");
		free_mlx(&cub);
		return (0);
	}
	else
	{
		everyinit(&cub);
		cub3d(&cub);
	}
}
