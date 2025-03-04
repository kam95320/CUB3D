/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:37:40 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/04 14:06:45 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	get_map_size(t_map *map, char **file)
{
	int i;
	int max_widht;
	int l_lenght;
	i = 0;
	max_widht = 0;
	l_lenght = 0;

	while (file[i])
	{
		l_lenght = ft_strlen(file[i]);
		if (l_lenght > max_widht)
			max_widht = l_lenght;
		i++;
	}
	map->height = i;
	map->width = max_widht;
    printf("\n");
    printf("----------get_map_size----------\n");
	printf("widht = %d,  height =  %d\n", map->width, map->height);
    printf("----------get_map_size----------\n");
}