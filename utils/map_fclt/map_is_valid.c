/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:16:58 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/05 14:18:43 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

bool	is_line_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (true);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}


bool	map_is_valid(t_cub *cub)
{
	int		j = 0;
	int		total_line = cub->map->L;
	char	**mp = cub->map->matrix;

	init_textures(cub);
	while (j < total_line)
	{
		int i = skip_space(mp, j, 0);
		if (!mp[j][i] || mp[j][i] == '\n')
		{
			j++;
			continue;
		}
		if (!is_good_print(cub, mp, i, j))
		{
			printf("❌ Ligne invalide à j = %d, i = %d : %s\n", j, i, mp[j]);
			free_textures(cub->txt);
			return (false);
		}
		j++;
	}
	if (!vrb_txt_valid(cub))
	{
		free_textures(cub->txt);
		return (false);
	}
	printf("✅ map_is_valid end\n");
	return (true);
}
