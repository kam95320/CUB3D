/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:56:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/30 18:11:46 by kahoumou         ###   ########.fr       */
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

	tab = NULL;
	tab = count_str(tab, mp);
	if (!tab)
		return (0);
	str = malloc(sizeof(int) * 3);
	return (rgb_is_number(tab, str));
}

bool	color(t_info_texture *txt, char *mp, int j, int *F_C)
{
	if (ft_isprint(mp[j + 1]))
	{
		print_error("error color file\n");
		return (false);
	}
	if (!txt->ceiling)
	{
		if (mp[j] == 'C' || mp[j] == 'F')
		{
			F_C = rgb(mp + j + 1);
			if (F_C == false)
			{
				print_error("error rgb\n");
				return (false);
			}
			if (floor_or_ceiling(mp[j], txt) == 1)
				txt->ceiling = rgb(mp);
			if (floor_or_ceiling(mp[j], txt) == 2)
				txt->floor = rgb(mp);
			hx_txt(txt, 'F');
			hx_txt(txt, 'C');
		}
	}
	return (true);
}
