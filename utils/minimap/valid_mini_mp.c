/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_mini_mp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:22:06 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/12 18:14:39 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

bool	coord(int coord, int size)
{
	if (coord < size)
		return (true);
	return (false);
}
void	is_valid_mnp_size(t_minilib_window *win, int y, int x, char *line)
{
	if (!coord(y + win->mn_mp.mn_mp_pos_wind_y, win->map_data.height)
		|| !coord(x + win->mn_mp.mn_mp_pos_wind_x, win->map_data.width))
		line[x] = ' ';
	else if ((int)win->player_info.fl_pl_pos_x == (x
			+ win->mn_mp.mn_mp_pos_wind_x)
		&& (int)win->player_info.fl_pl_pos_y == (y
			+ win->mn_mp.mn_mp_pos_wind_y))
		line[x] = 'P';
	else if (win->map_data.file[y + win->mn_mp.mn_mp_pos_wind_y][x
		+ win->mn_mp.mn_mp_pos_wind_x] == '1')
		line[x] = '1';
	else if (win->map_data.file[y + win->mn_mp.mn_mp_pos_wind_y][x
		+ win->mn_mp.mn_mp_pos_wind_x] == '0')
		line[x] = '0';
	else
		line[x] = ' ';
}

char	*mnp_l(t_minilib_window *win, int y)
{
	char	*line;
	int		x;

	line = ft_calloc(win->mn_mp.mini_mp_size + 1, sizeof(char));
	if (!line)
		return (NULL);
	x = 0;
	while (x < win->mn_mp.mini_mp_size)
	{
		is_valid_mnp_size(win, y, x, line);
		x++;
	}
	return (line);
}

int	dcl_mn_mp(t_minimap *mn_mp, int mp_sz, int pos)
{
	if (pos > mn_mp->mn_mp_w_dist && mp_sz - pos > mn_mp->mn_mp_w_dist + 1)
	{
		return (pos - mn_mp->mn_mp_w_dist);
	}
	if (pos > mn_mp->mn_mp_w_dist && mp_sz - pos <= mn_mp->mn_mp_w_dist + 1)
	{
		return (mp_sz - mn_mp->mini_mp_size);
	}
	return (0);
}