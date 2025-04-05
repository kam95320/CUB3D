/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_good_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:57:14 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/05 14:52:40 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"
#include <assert.h>
#include <string.h>

char	*txt_cond(char **mp, int i, int j)
{
	char	*line;
	char	*path;

	if (!mp || !mp[j])
		return (NULL);
	line = &mp[j][i];
	while (*line == ' ' || *line == '\t')
		line++;
	if ((line[0] == 'N' && line[1] == 'O') || (line[0] == 'S' && line[1] == 'O')
		|| (line[0] == 'W' && line[1] == 'E') || (line[0] == 'E'
			&& line[1] == 'A'))
	{
		path = ft_strtrim(line, "\n");
		if (!path)
			print_error("malloc failed in txt_cond");
		printf("line path =%s\n", path);
		return (path);
	}
	return (NULL);
}
char	*verif_direct(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return ("NO");
	if (line[0] == 'S' && line[1] == 'O')
		return ("SO");
	if (line[0] == 'W' && line[1] == 'E')
		return ("WE");
	if (line[0] == 'E' && line[1] == 'A')
		return ("EA");
	return (NULL);
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

	printf("\n----textures---\n");
	printf("line in textures =  %s\n", line);
	verif = verif_direct(line);
	printf("verif =  %s\n", verif);
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
			{
				printf("line =  %s\n", line);
				fill_textures(cub, line, verif);
			}
		}
		return (true);
	}
	free(line);
	if (!cub->txt[NO]->name && !cub->txt[SO]->name && !cub->txt[EA]->name
		&& !cub->txt[WE]->name)
		return (false);
	return (false);
}

void	fill_textures(t_cub *cub, char *line, char *verif)
{
	printf("----fill textures deb\n---");
	line = line + 2;
	if (!line)
		wgas(cub, "Textures", "Couldn't split line");
	while (*line == ' ' || *line == '\t')
		line++;
	printf("line =  %s\n", line);
	if (verif)
	{
		if (!ft_strcmp(verif, "NO"))
		{
			printf("pass  in  if verif\n");
			cub->txt[NO]->name = line;
			printf("cub->txt[NO]->name = %s\n", cub->txt[NO]->name);
		}
		if (!ft_strcmp(verif, "SO"))
		{
			printf("fill_textures line[S0] = %s\n", cub->txt[SO]->name = line);
			cub->txt[SO]->name = line;
		}
		if (!ft_strcmp(verif, "WE"))
			cub->txt[WE]->name = line;
		if (!ft_strcmp(verif, "EA"))
			cub->txt[EA]->name = line;
	}
	printf("----fill textures end\n---");
}

char	tk_ltr_f_c(char *ltr)
{
	int	i;

	i = 0;
	while (ltr[i])
	{
		if (ltr[i] == 'F')
		{
			return ('F');
		}
		if (ltr[i] == 'C')
		{
			return ('C');
		}
		i++;
	}
	// return (ltr[i]);
	return (0);
}

bool	is_good_print(t_cub *cub, char **mp, int i, int j)
{
	int		val;
	char	*t_c;
	char	ltr;

	ltr = mp[j][i];
	if (ltr == 'F' || ltr == 'C')
		ltr = tk_ltr_f_c(&mp[j][i]);
	t_c = txt_cond(mp, i, j);
	val = false;
	if (mp[j][i] == '0' || mp[j][i] == '1' || mp[j][i] == 'N' || mp[j][i] == 'S'
		|| mp[j][i] == 'W' || mp[j][i] == 'E')
	{
		val = true;
	}
	if (val && t_c != 0)
	{
		textures(cub, t_c);
		printf("\n----in is good print----\n");
		printf("cub->txt[NO]->name = %s\n", cub->txt[NO]->name);
		printf("cub->txt[SO]->name = %s\n", cub->txt[SO]->name);
		printf("cub->txt[EA]-> name = %s\n", cub->txt[EA]->name);
		printf("cub->txt[WE]-> name = %s\n", cub->txt[WE]->name);
	}
	if (ltr == 'F' || ltr == 'C')
	{
		fccolors(cub, mp[j], ltr);
		val = true;
	}
	return (val);
}
