/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_mem_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:42:13 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/23 16:06:05 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../../headers/utils.h"

bool	take_mem_map(t_cub *cub, two_d_t *two_d, char *mp)
{
	int	line_count;

	(void)two_d;
	line_count = nb_line(mp);
	cub->map = malloc(sizeof(t_map_data));
	if (!cub->map)
		return (print_error("Erreur d'allocation cub->map"), false);
	cub->map->L = line_count;
	cub->map->matrix = ft_calloc(line_count + 1, sizeof(char *));
	if (!cub->map->matrix)
		return (print_error("Erreur malloc matrix"), false);
	cub->map_name = mp;
	cub->fd = open(mp, O_RDONLY);
	if (cub->fd < 0)
		return (print_error("Erreur ouverture fichier"), false);
	completed_2d(two_d, cub);
	get_map_size(cub->map, cub->map->matrix);
	close(cub->fd);
	return (true);
}
