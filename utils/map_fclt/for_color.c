/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:56:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/23 17:31:46 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

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

static bool	*rgb(char *mp)
{
	int	*tab;

	if (!count_str)
		return (false);
	tab = str_malloc(3);
}

bool	color(t_info_texture *txt, char *mp, int j, int F_C)
{
	bool	bl;

	bl = false;
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
		}
	}
	return (bl);
}
