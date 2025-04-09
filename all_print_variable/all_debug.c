/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:33:15 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/09 18:35:06 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	all_debug(t_cub *cub)
{
    int i = 0;
    int j = 0;
    while(cub->map->matrix[j])
    {
        i = 0;
        while(cub->map->matrix[j][i])
        {
            printf("%c", cub->map->matrix[j][i]);
            i ++;
        }
        j ++;
    }
	debug_txt(cub);
	floor_dg_col(cub);
	ceiling_debug_col(cub);

}

void	debug_txt(t_cub *cub)
{
	printf("\n----debug_txt---\n");
	if (!cub->txt[NO])
	{
		printf("debug probleme  with txt\n");
	}
	printf("cub->txt[NO]->name = %s\n", cub->txt[NO]->name);
	printf("->txt[SO]->name = %s\n", cub->txt[SO]->name);
	printf("cub->txt[EA]-> name = %s\n", cub->txt[EA]->name);
	printf("cub->txt[WE]-> name = %s\n", cub->txt[WE]->name);
}

void	floor_dg_col(t_cub *cub)
{
	int	r;
	int	g;
	int	b;

	printf("\n-----debug floor-----\n");
	if (cub->map->floor->r)
	{
        printf("debug probleme  with map\n");
	}
   
	r = cub->map->floor->r;
	g = cub->map->floor->g;
	b = cub->map->floor->b;
	printf("cub->map->floor->r =  %d\n", r);
	printf("cub->map->floor->g =  %d\n", g);
	printf("cub->map->floor->b =  %d\n", b);
    printf("floor_hx =  %d\n", cub->map->floor_cl_hx);
}

void	ceiling_debug_col(t_cub *cub)
{
	printf("\n-----debug ceiling-----\n");
	if (!cub->map->ceiling->r)
	{
		printf("debug probleme  with map->eiling color\n");
	}
	printf("cub->map->ceiling->r =  %d\n", cub->map->ceiling->r);
	printf("cub->map->ceiling->g =  %d\n", cub->map->ceiling->g);
	printf("cub->map->ceiling->b =  %d\n", cub->map->ceiling->b);
	printf("ceiling_hx =  %d\n", cub->map->ceiling_cl_hx);

}