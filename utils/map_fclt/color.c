/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:56:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/27 15:53:23 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

static int	rgb_is_number(char **s1, char *s2)
{
	int	i;

	// char	*result;
	i = 0;
	while (s2[i++])
	{
		s2[i] = ft_atoi(s2[i]);
		if (s2[i] == -1 || ft_isdigit != 2048)
		{
			free_tab((void **)s1);
			free(s2);
			reuturn(0);
		}
	}
	free_tab((void **)s1);
	return (s2);
}
static bool	count_str(char **str, char *mp)
{
	int	i;

	str = ft_split(mp, ',');
	i = 0;
	while (str[i])
		i++;
	if (i == 3)
		return (true);
	else
	{
		print_error("rgb file not 3\n");
		free_tab((void **)str);
		return (false);
	}
	return (true);
}

static int	*rgb(char *mp)
{
	int	**tab;

	if (!count_str(tab, mp))
		return (false);
	tab = str_malloc(3);
	return (rgb_is_number(tab, mp));
}

bool	color(t_info_texture *txt, char *mp, int j, int F_C)
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
			if (floor_or_ceiling(mp[j]) == 1)
				txt->ceiling = rgb(mp);
			if (floor_or_ceiling(mp[j]) == 2)
				txt->floor = rgb(mp);
			txt->hxd_floor = hx_txt(txt, 'F');
			txt->hxd_ceiling = hx_txt(txt, 'C');
		}
	}
	return (true);
}
