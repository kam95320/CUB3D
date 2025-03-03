/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:56:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/03 14:30:56 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

static int	*rgb_is_number(char **s1, int *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		s2[i] = ft_atoi(s1[i]);
		if (s2[i] == -1)
		{
			print_error("is not an integer\n");
			free_tab((void **)s1);
			free(s2);
			return (0);
		}
		i++;
	}
	free_tab((void **)s1);
	return (s2);
}

static char	**count_str(char **tab, char *mp)
{
	int		i;
	char	*str;

	i = 0;
	while (mp[i] == 32 || mp[i] == 'C' || mp[i] == 'F')
		i++;
	str = i + mp;
	tab = ft_split(str, ',');
	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
	{
		print_error("rgb file not 3\n");
		free_tab((void **)tab);
		return (0);
	}
	return (tab);
}

static int	*rgb(char *mp)
{
	char	**tab;
	int		*str;
	int		*result;

	tab = count_str(NULL, mp);
	if (!tab)
		return (NULL);
	str = malloc(sizeof(int) * 3);
	if (!str)
	{
		print_error("rgb malloc * 3 in rgb  failed\n");
		free_tab((void **)tab);
		return (NULL);
	}
	result = rgb_is_number(tab, str);
	if (!result)
	{
		free(str);
		return (NULL);
	}
	return (result);
}

bool	color(t_info_texture *txt, char *mp, char ltr)
{
	if (ltr == 'C' || ltr == 'F')
	{
		if (ltr == 'C' && !txt->ceiling)
		{
			txt->ceiling = rgb(mp + 2);
		}
		if (ltr == 'F' && !txt->floor)
		{
			txt->floor = rgb(mp + 2);
		}
		if (!txt->ceiling && !txt->floor)
		{
			print_error("ERROR: Ceiling or floor RGB values are not set.\n");
			return (false);
		}
	}
	return (true);
}
