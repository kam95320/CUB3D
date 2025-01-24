/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_good_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:57:14 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/24 11:36:05 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

static int	txt_cond(t_info_texture *txt, char **mp, int i, int j)
{
	if (mp[j] == 'N' && mp[j + 1] == 'O')
		return (1);
	if (mp[j] == 'S' && mp[j + 1] == 'O')
		return (2);
	if (mp[j] == 'W' && mp[j + 1] == 'E')
		return (3);
	if (mp[j] == 'E' && mp[j + 1] == 'A')
		return (4);
	return (0);
}

static char	*pth_txt(char *mp, int j)
{
	int		len;
	int		i;
	char	*str;

	j = manage_txt_space(mp, j, 1);
	len = manage_txt_space(mp, j, 2);
	str = str_malloc(len);
	i = 0;
	str[i] = manage_txt_space(mp, j, 3);
	str[i] = '\0';
	j = j + manage_txt_space(mp, j, 4);
	if (str[j] != '\0' && str[j] != '\n')
	{
		free(str);
		str = NULL;
	}
	return (str);
}

static void	vl_direct(t_info_texture *txt, char *mp, int j, int t_c)
{
	if (t_c == 1 && !txt->direct_north)
		txt->direct_north = pth_txt(mp, j + 2);
	if (t_c == 2 && !txt->direct_south)
		txt->direct_south = pth_txt(mp, j + 2);
	if (t_c == 3 && !txt->direct_east)
		txt->direct_west = pth_txt(mp, j + 2);
	if (t_c == 2 && !txt->direct_east)
		txt->direct_east = pth_txt(mp, j + 2);
}

bool	is_good_print(t_info_texture *txt, char **mp, int i, int j)
{
	int	val;
	int	t_c;

	t_c = txt_cond(txt, mp, i, j);
	val = false;
	if (mp[i][j] >= 33 && mp[i][j] < 127)
		val = true;
	if (mp[i][j] >= 48 && mp[i][j] < 58)
		val = true;
	if (val == true && t_c != 0)
	{
		vl_direct(txt, mp[i], j, t_c);
	}
	val = color(txt, mp, i, txt->ceiling);
	return (val);
}
