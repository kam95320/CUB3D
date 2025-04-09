/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_good_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:57:14 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/09 18:56:11 by kahoumou         ###   ########.fr       */
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
	return (0);
}
int	hex_rgb(t_rgb *rgb)
{
	int	hx_val;
	int	r;
	int	g;
	int	b;

	r = rgb->r * (256 * 256);
	g = rgb->g * 256;
	b = rgb->b;
	hx_val = r + g + b;
	return (hx_val);
}
void	convert_color(t_cub *cub, char ltr)
{
	if (ltr == 'F')
	{
		cub->map->floor_cl_hx = hex_rgb(cub->map->floor);
		return ;
	}
	if (ltr == 'C')
	{
		cub->map->ceiling_cl_hx = hex_rgb(cub->map->ceiling);
		return ;
	}
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
	}
	if (ltr == 'F' || ltr == 'C')
	{
		fccolors(cub, mp[j], ltr);
		convert_color(cub, ltr);
		val = true;
	}
	return (val);
}
