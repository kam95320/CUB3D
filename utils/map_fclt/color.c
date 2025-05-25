/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:56:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/22 13:55:59 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

// static int	*rgb_is_number(char **s1, int *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i])
// 	{
// 		s2[i] = ft_atoi(s1[i]);
// 		if (s2[i] == -1)
// 		{
// 			print_error("is not an integer\n");
// 			free_tab((void **)s1);
// 			free(s2);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	free_tab((void **)s1);
// 	return (s2);
// }

void	fccolors(t_cub *cub, char *line, char ltr)
{
	if (line && ltr)
	{
		if (ltr == 'F')
		{
			fill_floor(cub, line);
			return ;
		}
		else if (ltr == 'C')
		{
			fill_ceiling(cub, line);
			return ;
		}
		free(line);
		if ((cub->map->floor && cub->map->ceiling))
			return ;
		line = ft_strtrim(line, "\n");
		if (!cub->map->floor || !cub->map->ceiling)
			wgas(cub, "fccolors",
				"First lines should contain address Floor and ceiling value");
	}
}
