/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_or_ceiling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:04:53 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/22 14:40:13 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../../headers/utils.h"

int	floor_or_ceiling(char lt, t_info_texture *txt)
{
	(void)txt;
	if (lt == 'C')
	{
		return (1);
	}
	if (lt == 'F')
	{
		return (2);
	}
	return (0);
}

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
