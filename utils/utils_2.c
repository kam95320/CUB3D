/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:02:08 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/22 17:29:17 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	freend(t_cub *cub)
{
	free_map(cub);
	if (cub->map_name)
		free(cub->map_name);
	if (cub->data)
		free(cub->data);
	if (cub->cam)
		free(cub->cam);
	if (cub->ray)
		free(cub->ray);
}

void	next_line(t_cub *cub, char **line)
{
	free(*line);
	*line = get_next_line(cub->fd);
}

void	wgas(t_cub *cub, char *arg, char *str)
{
	printf("Error\n");
	if (arg)
		printf("%s", arg);
	if (str)
		printf(": %s", str);
	printf("\n");
	freend(cub);
	if (cub->fd > 0)
		close(cub->fd);
	exit(1);
}

void	wegotasplituation(struct spt x)
{
	int	i;

	i = 0;
	while (x.split[i] && i <= x.op)
	{
		free(x.split[i]);
		i++;
	}
	free(x.split);
}

void	free_map(t_cub *cub)
{
	if (cub->map)
	{
		if (cub->map->floor)
			free(cub->map->floor);
		if (cub->map->ceiling)
			free(cub->map->ceiling);
		if (cub->map->matrix)
			fsplit(cub->map->matrix);
	}
	if (cub->fd > 0)
		gnl_free(cub->fd);
	free(cub->map);
}
