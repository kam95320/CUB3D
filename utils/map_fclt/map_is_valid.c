/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:16:58 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/28 10:09:40 by kahoumou         ###   ########.fr       */
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

bool	good_print_verif(t_cub *cub, char **mp, int i, int j)
{
	if (!is_good_print(cub, mp, i, j))
	{
		printf("❌ Ligne invalide à j = %d, i = %d : %s\n", j, i, mp[j]);
		free_textures(cub->txt);
		return (false);
	}
	return (true);
}

bool	verif_valid_txt(t_cub *cub)
{
	if (!vrb_txt_valid(cub))
	{
		free_textures(cub->txt);
		return (false);
	}
	return (true);
}

bool	map_is_valid(t_cub *cub)
{
	int		j;
	int		total_line;
	char	**mp;
	int		i;

	j = 0;
	total_line = cub->map->L;
	mp = cub->map->matrix;
	init_textures(cub);
	while (j < total_line)
	{
		i = skip_space(mp, j, 0);
		if (!mp[j][i] || mp[j][i] == '\n')
		{
			j++;
			continue ;
		}
		if (true == good_print_verif(cub, mp, i, j))
			j++;
	}
	if (false == player_outside_map(mp))
	{
		return (false);
	}
	if (false == verif_valid_txt(cub))
		return (false);
	if (false == check_close_map(mp))
		return (false);
	return (true);
}
