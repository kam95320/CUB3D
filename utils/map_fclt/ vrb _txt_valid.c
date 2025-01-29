/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    vrb _txt_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:02:47 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/29 19:02:51 by kahoumou         ###   ########.fr       */
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
}
