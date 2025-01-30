/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vrb_txt_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:06:10 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/30 17:10:46 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

bool	vrb_txt_valid(t_info_texture *txt)
{
	if (!txt->ceiling || !txt->floor)
		return (false);
	if (!txt->direct_east || !txt->direct_north || !txt->direct_south)
		return (false);
	if (!txt->direct_west)
		return (false);
	return (true);
}
