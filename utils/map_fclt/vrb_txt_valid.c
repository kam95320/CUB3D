/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vrb_txt_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:06:10 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/02 10:28:40 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

bool	vrb_txt_valid(t_cub *cub)
{
	if (!cub->map->ceiling || !cub->map->floor)
	{
		print_error("❌ Missing ceiling or floor color\n");
		return (false);
	}
	if (!cub->txt[NO] || !cub->txt[SO] || !cub->txt[WE] || !cub->txt[EA])
	{
		if (!cub->txt[NO]) print_error("❌ Missing texture: North\n");
		if (!cub->txt[SO]) print_error("❌ Missing texture: South\n");
		if (!cub->txt[WE]) print_error("❌ Missing texture: West\n");
		if (!cub->txt[EA]) print_error("❌ Missing texture: East\n");
		return (false);
	}
	return (true);
}
