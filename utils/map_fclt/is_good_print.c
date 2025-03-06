/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_good_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:57:14 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/06 15:28:40 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"
#include <assert.h>
#include <string.h>

static int	txt_cond(char **mp, int i, int j)
{
	while (mp[i][j] == ' ' || mp[i][j] == '\t')
		j++;
	if (!mp[i][j] || !mp[i][j + 1])
		return (0);
	if (mp[i][j] == 'N' && mp[i][j + 1] == 'O')
		return (1);
	if (mp[i][j] == 'S' && mp[i][j + 1] == 'O')
		return (2);
	if (mp[i][j] == 'W' && mp[i][j + 1] == 'E')
		return (3);
	if (mp[i][j] == 'E' && mp[i][j + 1] == 'A')
		return (4);
	return (0);
}

static char	*pth_txt(char *mp, int j)
{
	int		len;
	char	*str;

	str = NULL;
	j = manage_txt_space(mp, j, 1);
	len = manage_txt_space(mp, j, 2) - j;
	if (len <= 0)
		return (NULL);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, mp + j, len + 1);
	str[len] = '\0';
	return (str);
}

static void	vl_direct(t_info_texture *txt, char *mp, int j, int t_c)
{
	if (t_c == 1 && !txt->direct_north)
		txt->direct_north = pth_txt(mp, j + 2);
	if (t_c == 2 && !txt->direct_south)
		txt->direct_south = pth_txt(mp, j + 2);
	if (t_c == 3 && !txt->direct_west)
		txt->direct_west = pth_txt(mp, j + 2);
	if (t_c == 4 && !txt->direct_east)
		txt->direct_east = pth_txt(mp, j + 2);
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
	return (ltr[i]);
}

bool	is_good_print(t_info_texture *txt, char **mp, int i, int j)
{
	int		val;
	int		t_c;
	char	ltr;

	ltr = tk_ltr_f_c(&mp[j][0]);
	t_c = txt_cond(mp, i, j);
	val = false;
	if (mp[i][j] == '0' || mp[i][j] == '1' || mp[i][j] == 'N' || mp[i][j] == 'S'
		|| mp[i][j] == 'W' || mp[i][j] == 'E')
	{
		val = true;
	}
	if (val && t_c != 0)
		vl_direct(txt, mp[i], j, t_c);
	if (ltr == 'F' || ltr == 'C')
	{
		val = color(txt, mp[j], ltr);
	}
	return (val);
}
