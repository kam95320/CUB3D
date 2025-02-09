/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hx_txt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:49:16 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/09 18:19:00 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	hx_txt(t_info_texture *txt, char lt)
{
	unsigned int	rs;
	int				red = 0, green = 0, blue;
	int				*var;

	red = 0, green = 0, blue = 0;
	var = NULL;
	if (lt == 'C' && txt->ceiling)
		var = txt->ceiling;
	if (lt == 'F' && txt->floor)
		var = txt->floor;
	if (!var)
	{
		printf("❌ Erreur: Tentative de conversion de couleur non initialisée pour '%c'\n",
			lt);
		return ;
	}
	red = var[0];
	green = var[1];
	blue = var[2];
	rs = ((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff);
	if (lt == 'C')
		txt->hxd_ceiling = rs;
	if (lt == 'F')
		txt->hxd_floor = rs;
	printf("✅ Conversion RGB -> HEX pour '%c' : #%06X\n", lt, rs);
}
