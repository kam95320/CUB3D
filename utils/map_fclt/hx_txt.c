/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hx_txt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:49:16 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/11 18:32:08 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

static void	init_txt_var(t_info_texture *txt)
{
	txt->red = 0;
	txt->green = 0;
	txt->blue = 0;
}

void	hx_txt(t_info_texture *txt, char lt)
{
	unsigned int	rs;
	int				*var;

	init_txt_var(txt);
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
	txt->red = var[0];
	txt->green = var[1];
	txt->blue = var[2];
	rs = ((txt->red & 0xff) << 16) + ((txt->green & 0xff) << 8)
		+ (txt->blue & 0xff);
	if (lt == 'C')
		txt->hxd_ceiling = rs;
	if (lt == 'F')
		txt->hxd_floor = rs;
}
