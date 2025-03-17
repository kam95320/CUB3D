/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completed_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:21:54 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/17 15:30:41 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../../headers/utils.h"

int	init_var(two_d_t *two_d, t_minilib_window *data)
{
	(void)data;
	two_d->i = 0;
	two_d->col = 0;
	two_d->row = 0;
	// two_d->line = get_next_line(data->map_data.fd);
	two_d->line = NULL;
	// if (!two_d->line)
	// 	return (-1);
	return (0);
}

void	completed_2d(two_d_t *two_d, t_minilib_window *data)
{
	char	*tmp_line;

	if (-1 == init_var(two_d, data))
		return ;
	while (1)
	{
		tmp_line = get_next_line(data->map_data.fd);
		if (NULL == tmp_line)
			break ;
		two_d->line = tmp_line;
		if (two_d->row >= data->map_data.line_len)
		{
			print_error("Erreur : Dépassement de mémoire dans completed_2d\n");
			break ;
		}
		data->map_data.file[two_d->row] = ft_calloc(ft_strlen(two_d->line) + 1,
				sizeof(char));
		if (!data->map_data.file[two_d->row])
		{
			print_error("Problème avec malloc dans completed_2d\n");
			free_tab((void **)data->map_data.file);
			break ;
		}
		ft_strlcpy(data->map_data.file[two_d->row], two_d->line,
			ft_strlen(two_d->line) + 1);
		free(two_d->line);
		two_d->row++;
	}
	data->map_data.file[two_d->row] = NULL;
}
