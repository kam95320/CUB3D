/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:39:33 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/13 16:11:47 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	nb_line(char *map)
{
	char	*get_line;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		print_error("error open with nb_line\n");
		return (false);
	}
	get_line = get_next_line(fd);
	while (get_line)
	{
		i++;
		free(get_line);
		get_line = get_next_line(fd);
	}
	close(fd);
	return (i);
}
