/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vrb_txt_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:06:10 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/03 14:43:03 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

bool	vrb_txt_valid(t_info_texture *txt)
{
	if (!txt->ceiling && !txt->floor)
	{
		print_error("txt->ceiling or txt->floor empty\n");
		return (false);
	}
	if (!txt->direct_east && !txt->direct_north && !txt->direct_south)
	{
		print_error("txt->direct_east empty\n");
		print_error("txt->direct_north empty\n");
		print_error("txt->direct_south empty\n");
		return (false);
	}
	if (!txt->direct_west)
		return (false);
	return (true);
}
