/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:02:47 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/28 17:49:10 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	fill_textures(t_cub *cub, char *line, char *verif)
{
	line = line + 2;
	if (!line)
		wgas(cub, "Textures", "Couldn't split line");
	while (*line == ' ' || *line == '\t')
		line++;
	if (verif)
	{
		if (!ft_strcmp(verif, "NO"))
		{
			cub->txt[NO]->name = line;
		}
		if (!ft_strcmp(verif, "SO"))
		{
			cub->txt[SO]->name = line;
		}
		if (!ft_strcmp(verif, "WE"))
			cub->txt[WE]->name = line;
		if (!ft_strcmp(verif, "EA"))
			cub->txt[EA]->name = line;
	}
}

void	init_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		cub->txt[i] = malloc(sizeof(t_txt));
		if (!cub->txt[i])
			wgas(cub, "Textures", "malloc t_txt failed");
		cub->txt[i]->name = NULL;
		cub->txt[i]->img = NULL;
		i++;
	}
}

bool	textures(t_cub *cub, char *line)
{
	char	*verif;

	verif = verif_direct(line);
	if (!verif)
		return (false);
	if (verif)
	{
		while (*line == ' ' || *line == '\t')
			line++;
		if ((!cub->txt[NO] || !cub->txt[NO]->name) || (!cub->txt[SO]
				|| !cub->txt[SO]->name) || (!cub->txt[EA]
				|| !cub->txt[EA]->name) || (!cub->txt[WE]
				|| !cub->txt[WE]->name))
		{
			if (verif)
				fill_textures(cub, line, verif);
		}
		return (true);
	}
	free(line);
	if (!cub->txt[NO]->name && !cub->txt[SO]->name && !cub->txt[EA]->name
		&& !cub->txt[WE]->name)
		return (false);
	return (false);
}
