/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_good_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:57:14 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/22 19:09:48 by kahoumou         ###   ########.fr       */
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
		if (t_c == 1 && !txt->direct_north)
			txt->direct_north = pth_txt(mp[i], j + 2);
		if (t_c == 2 && !txt->direct_south)
			txt->direct_south = pth_txt(mp[i], j + 2);
		if (t_c == 3 && !txt->direct_east)
			txt->direct_west = pth_txt(mp[i], j + 2);
		if (t_c == 2 && !txt->direct_east)
			txt->direct_east = pth_txt(mp[i], j + 2);
	}
}
