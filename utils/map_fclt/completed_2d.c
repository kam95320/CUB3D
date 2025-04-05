/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completed_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:21:54 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/04 09:24:50 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../../headers/utils.h"

int init_var(two_d_t *two_d)
{
	two_d->i = 0;
	two_d->col = 0;
	two_d->row = 0;
	two_d->line = NULL;
	return (0);
}

void completed_2d(two_d_t *two_d, t_cub *cub)
{
	char *tmp_line;

	if (-1 == init_var(two_d))
		return ;
	while (1)
	{
		tmp_line = get_next_line(cub->fd);
		if (NULL == tmp_line)
			break ;
		two_d->line = tmp_line;
		if (two_d->row >= cub->map->L)
		{
			print_error("Erreur : Dépassement de mémoire dans completed_2d");
			break ;
		}
		cub->map->matrix[two_d->row] = ft_calloc(ft_strlen(two_d->line) + 1, sizeof(char));
		if (!cub->map->matrix[two_d->row])
		{
			print_error("Problème avec malloc dans completed_2d");
			free_tab((void **)cub->map->matrix);
			break ;
		}
		ft_strlcpy(cub->map->matrix[two_d->row], two_d->line, ft_strlen(two_d->line) + 1);
		free(two_d->line);
		two_d->row++;
	}
	cub->map->matrix[two_d->row] = NULL;
}
