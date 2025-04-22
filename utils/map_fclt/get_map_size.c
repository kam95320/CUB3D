/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:37:40 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/22 13:57:28 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	get_map_size(t_map_data *map, char **file)
{
	int	i;
	int	max_width;
	int	l_length;

	i = 0;
	max_width = 0;
	l_length = 0;
	while (file[i])
	{
		l_length = ft_strlen(file[i]);
		if (l_length > max_width)
			max_width = l_length;
		i++;
	}
	map->L = i;
	map->l = max_width;
}
