/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:47:05 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/31 15:58:54 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H
# include "image.h"
typedef struct s_minimap
{
	char		**mini_mp;
	t_manip_img	mini_img;
	int			mini_mp_size;
	int			mn_mp_pos_wind_y;
	int			mn_mp_pos_wind_x;
	int			mn_mp_w_dist;
	int			mn_mp_case_size;

}				t_minimap;

#endif //  MINIMAP_H