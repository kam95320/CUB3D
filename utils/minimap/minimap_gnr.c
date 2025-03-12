/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_gnr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:28:02 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/12 18:17:09 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"


static intside_of_mnmp(t_minimap *minimap, int mapsize, int pos)
{
    int offset;

    if (pos <= minimap->mn_mp_w_dist)
        offset = 0;
    else if (mapsize - pos <= minimap->mn_mp_w_dist + 1)
        offset = mapsize - minimap->mini_mp_size;
    else
        offset = pos - minimap->mn_mp_w_dist;

    if (offset < 0)
        offset = 0;

    return offset;
}



void init_var_mnmp(t_minilib_window *win)
{
	t_minimap mn_mp;
	win->mn_mp.mini_mp = NULL;
	win->mn_mp.mini_img = &win->minimap_info.mini_img;
	win->mn_mp.mn_mp_w_dist = 4;
	win->mn_mp.mini_mp_size = (2 * win->mn_mp.mn_mp_w_dist) + 1;
	win->mn_mp.mn_mp_case_size = 128 / (2 * win->mn_mp.mn_mp_w_dist);
	win->mn_mp.mn_mp_pos_wind_x = side_of_mnmp(&win->mn_mp,
			win->map_data.width, (int)win->player_info.fl_pl_pos_x);
	win->mn_mp.mn_mp_pos_wind_y = side_of_mnmp(&win->mn_mp,
			win->map_data.height, (int)win->player_info.fl_pl_pos_y);
	win->mn_mp.mini_mp = gnrt_mn_mp(win, &mn_mp);
}


void	render_minimap(t_minilib_window *win)
{
	init_var_mnmp(win);
	if (!win->mn_mp.mini_mp)
	{
		print_error("minimap probleme\n");
		return ;
	}
	open_mn_mp(win);
	free_tab((void **)win->mn_mp.mini_mp);
}
