/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completed_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:21:54 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/14 12:58:03 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../../headers/utils.h"

int	init_var(two_d_t *two_d, t_minilib_window *data)
{
	two_d->i = 0;
	two_d->col = 0;
	two_d->row = 0;
	two_d->line = get_next_line(data->map_data.fd);
	if (!two_d->line)
		return (-1);
	return (0);
}

void	completed_2d(two_d_t *two_d, t_minilib_window *data)
{
	if (!init_var(two_d, data))
		return ;
	while (two_d->line != NULL)
	{
		data->map_data.file[two_d->row] = ft_calloc(ft_strlen(two_d->line) + 1,
				sizeof(char));
		if (!data->map_data.file[two_d->row])
		{
			print_error("probleme with malloc competed_2d\n");
			return (free_tab((void **)data->map_data.file));
		}
		while (two_d->line[two_d->i])
			data->map_data.file[two_d->row][two_d->col++] = two_d->line[two_d->i++];
		data->map_data.file[two_d->row++][two_d->col] = '\0';
		two_d->col = 0;
		two_d->i = 0;
		two_d->line = get_next_line(data->map_data.fd);
		free(two_d->line);
	}
	data->map_data.file[two_d->row] = NULL;
}
