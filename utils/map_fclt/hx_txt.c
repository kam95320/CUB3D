/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hx_txt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:49:16 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/06 16:25:37 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	hx_txt(t_info_texture *txt, char lt, int *rgb)
{
	unsigned int	rs;

	txt->red = rgb[0];
	txt->green = rgb[1];
	txt->blue = rgb[2];
	rs = ((txt->red & 0xff) << 16) + ((txt->green & 0xff) << 8)
		+ (txt->blue & 0xff);
	if (lt == 'C')
		txt->hxd_ceiling = rs;
	if (lt == 'F')
		txt->hxd_floor = rs;
}
