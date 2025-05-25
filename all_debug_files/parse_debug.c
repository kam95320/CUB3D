/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:33:15 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/12 19:39:33 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	map_db_print(t_cub *cub)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = cub->map->matrix;
	printf(GREEN "\n----- DEBUG MAP MATRIX -----\n" RESET);
	while (cub->map->matrix[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '0')
				printf(RED "%c" RESET, cub->map->matrix[j][i]);
			else if (map[j][i] == '1')
				printf(GREEN "%c" RESET, cub->map->matrix[j][i]);
			else if (txt_cond(map, i, j))
			{
				printf(LIGHT_BLUE "%s\n" RESET, txt_cond(map, i, j));
				break ;
			}
			else if (map[j][i] == 'F' || map[j][i] == 'C')
			{
				printf(RED "%c" RESET, map[j][i++]);
				while (map[j][i] != '\n')
					printf(CYAN "%c" RESET, map[j][i++]);
				break ;
			}
			else if (map[j][i] == 'N')
				printf(YELLOW "%c" RESET, map[j][i]);
			else
				printf(SOFT_GREEN "%c" RESET, map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

void	debug_txt(t_cub *cub)
{
	printf(GREEN "\n---- DEBUG TEXTURE NAME ----\n" RESET);
	if (!cub->txt[NO])
		printf(SOFT_GREEN "🛑 Problème avec la texture NO\n" RESET);
	printf(SOFT_GREEN "cub->txt[NO]->name = %s\n" RESET, cub->txt[NO]->name);
	printf(SOFT_GREEN "->txt[SO]->name = %s\n" RESET, cub->txt[SO]->name);
	printf(SOFT_GREEN "cub->txt[EA]->name = %s\n" RESET, cub->txt[EA]->name);
	printf(SOFT_GREEN "cub->txt[WE]->name = %s\n" RESET, cub->txt[WE]->name);
}

void	floor_dg_col(t_cub *cub)
{
	int	r;
	int	g;
	int	b;

	printf(GREEN "\n----- DEBUG FLOOR -----\n" RESET);
	if (!cub->map->floor->r)
		printf(RED "🛑 Problème avec les couleurs du sol\n" RESET);
	r = cub->map->floor->r;
	g = cub->map->floor->g;
	printf(SOFT_GREEN "cub->map->floor->r = %d\n" RESET, r);
	b = cub->map->floor->b;
	printf(SOFT_GREEN "cub->map->floor->g = %d\n" RESET, g);
	printf(SOFT_GREEN "cub->map->floor->b = %d\n" RESET, b);
	printf(SOFT_GREEN "floor_hx = %d\n" RESET, cub->map->floor_cl_hx);
}

void	ceiling_debug_col(t_cub *cub)
{
	printf(GREEN "\n----- DEBUG CEILING -----\n" RESET);
	if (!cub->map->ceiling->r)
		printf(RED "🛑 Problème avec les couleurs du plafond\n" RESET);
	printf(SOFT_GREEN "cub->map->ceiling->r = %d\n" RESET,
		cub->map->ceiling->r);
	printf(SOFT_GREEN "cub->map->ceiling->g = %d\n" RESET,
		cub->map->ceiling->g);
	printf(SOFT_GREEN "cub->map->ceiling->b = %d\n" RESET,
		cub->map->ceiling->b);
	printf(SOFT_GREEN "ceiling_hx = %d\n" RESET, cub->map->ceiling_cl_hx);
}
void	debug_texture_h_w(t_cub *cub)
{
	printf(GREEN"\n-----DEBUG TEXTURE HEIGHT-----\n"RESET);
	printf(SOFT_GREEN "cub->txt[NO]->height = %d\n" RESET,
		cub->txt[NO]->height);
	printf(SOFT_GREEN "cub->txt[SO]->height = %d\n" RESET,
		cub->txt[SO]->height);
	printf(SOFT_GREEN "cub->txt[EA]->height = %d\n" RESET,
		cub->txt[EA]->height);
	printf(SOFT_GREEN "cub->txt[WE]->height = %d\n" RESET,
		cub->txt[WE]->height);
	printf(GREEN"\n-----DEBUG TEXTURE WIDTH------\n"RESET);
	printf(SOFT_GREEN "cub->txt[NO]->width = %d\n" RESET, cub->txt[NO]->width);
	printf(SOFT_GREEN "cub->txt[SO]->width = %d\n" RESET, cub->txt[SO]->width);
	printf(SOFT_GREEN "cub->txt[EA]->width = %d\n" RESET, cub->txt[EA]->width);
	printf(SOFT_GREEN "cub->txt[WE]->width = %d\n" RESET, cub->txt[WE]->width);
}
void	debug_addr_img(t_cub *cub)
{
	printf(GREEN"\n-----DEBUG TEXTURE IMAGE-----\n"RESET);
	printf(SOFT_GREEN "cub->txt[NO]->img = %p\n" RESET, cub->txt[NO]->img);
	printf(SOFT_GREEN "cub->txt[SO]->img = %p\n" RESET, cub->txt[SO]->img);
	printf(SOFT_GREEN "cub->txt[EA]->img = %p\n" RESET, cub->txt[EA]->img);
	printf(SOFT_GREEN "cub->txt[WE]->img = %p\n" RESET, cub->txt[WE]->img);
}
void	texture_debug(t_txt *txt, t_cub *cub)
{
	printf(GREEN "\n----- TEXTURE DEBUG -----\n" RESET);
	if (!txt)
	{
		printf(RED "🛑 Problème de texture (txt NULL)\n" RESET);
		return ;
	}
	printf(SOFT_GREEN "txt->addr = %p\n" RESET, cub->data->addr);
	printf(SOFT_GREEN "txt->bits_per_pixel = %d\n" RESET, txt->bits_per_pixel);
	printf(SOFT_GREEN "txt->endian = %d\n" RESET, txt->endian);
	printf(SOFT_GREEN "txt->height = %d\n" RESET, txt->height);
	debug_addr_img(cub);
	debug_texture_h_w(cub);
	printf(SOFT_GREEN "txt->size_line = %d\n" RESET, txt->size_line);
}

void	all_debug(t_cub *cub)
{
	map_db_print(cub);
	floor_dg_col(cub);
	ceiling_debug_col(cub);
	texture_debug(&cub->texture, cub);
	debug_txt(cub);
	debug_player(cub->player);
	debug_raycasting(cub->ray);
}
