/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:56:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/10 15:35:37 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

static int	*rgb_is_number(char **s1, int *s2)
{
	int	i;

	i = 0;
	while (s1[i++])
	{
		s2[i] = ft_atoi(s1[i]);
		if (s2[i] == -1 || ft_isdigit(s2[i]) != 2048)
		{
			free_tab((void **)s1);
			free(s2);
			return (0);
		}
	}
	free_tab((void **)s1);
	return (s2);
}

static char	**count_str(char **tab, char *mp)
{
	int	i;
	printf("pass in count_str | mp =  %s\n\n", mp);
	tab = ft_split(mp, ',');
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
	printf("pass  in rgb | mp  = %s\n", mp);
	tab = count_str(NULL, mp);
	if (!tab)
		return (NULL);
	str = malloc(sizeof(int) * 3);
	if (!str)
	{
		free_tab((void **)tab);
		return (NULL);
	}
	result = rgb_is_number(tab, str);
	free_tab((void **)tab);
	if (!result)
	{
		free(str);
		return (NULL);
	}
	return (result);
}

bool	color(t_info_texture *txt, char *mp, char ltr)
{
	printf("pass in color ltr =  %c\n\n", ltr);
	int	*rgb_values;

	if (ltr == 'C' || ltr == 'F')
	{
			printf("pass in color =  %s\n\n", mp);
		rgb_values = rgb(mp);
		if (rgb_values == NULL)
		{
			print_error("error rgb\n");
			return (false);
		}
		if (floor_or_ceiling(ltr, txt) == 1)
			txt->ceiling = rgb_values;
		if (floor_or_ceiling(ltr, txt) == 2)
			txt->floor = rgb_values;
		if (!txt->ceiling || !txt->floor)
		{
			print_error("ERROR: Ceiling or floor RGB values are not set.\n");
			return (false);
		}
		hx_txt(txt, 'F');
		hx_txt(txt, 'C');
		printf("Floor: %d, %d, %d\n", txt->floor[0], txt->floor[1],
			txt->floor[2]);
		printf("Ceiling: %d, %d, %d\n", txt->ceiling[0], txt->ceiling[1],
			txt->ceiling[2]);
	}
	return (true);
}
