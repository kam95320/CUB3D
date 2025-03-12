/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:47:05 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/12 18:52:35 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H
# include "image.h"
typedef struct s_minimap
{
	char		**mini_mp;
	t_manip_img	*mini_img;
	int			mini_mp_size;
	int			mn_mp_pos_wind_y;
	int			mn_mp_pos_wind_x;
	int			mn_mp_w_dist;
	int			mn_mp_case_size;

}				t_minimap;

#endif //  MINIMAP_H

char			**gnrt_mn_mp(t_minilib_window *data, t_minimap *mp);
void			is_valid_mnp_size(t_minilib_window *win, int y, int x,
					char *line);
char			*mnp_l(t_minilib_window *win, int y);
int				dcl_mn_mp(t_minimap *mn_mp, int mp_sz, int pos);
void			put_img_mnp(t_minilib_window *win, t_minimap *minimap);
void	init_mnp(t_minilib_window *win, t_manip_img *image, int width,
	int height);
