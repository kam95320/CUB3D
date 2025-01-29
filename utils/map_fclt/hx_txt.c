/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hx_txt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:49:16 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/29 19:03:44 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	hx_txt(t_info_texture *txt, char lt)
{
	unsigned int	rs;
	int				red;
	int				green;
	int				blue;
	int				*var;

	if (lt == 'C')
		var = txt->ceiling;
	if (lt == 'F')
		var = txt->floor;
	red = var[0];
	green = var[1];
	blue = var[2];
	rs = ((red & 0xff) << 16 + (green & 0xff) << 8) + (blue & 0xff);
	if (lt == 'C')
		txt->hxd_ceiling = rs;
	if (lt == 'F')
		txt->hxd_floor = rs;
}
