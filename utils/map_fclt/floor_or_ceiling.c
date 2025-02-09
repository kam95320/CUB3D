/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_or_ceiling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:04:53 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/09 18:16:48 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../../headers/utils.h"

int	floor_or_ceiling(char lt, t_info_texture *txt)
{
	if (lt == 'C' && txt->ceiling == NULL)
		return (1);
	if (lt == 'F' && txt->floor == NULL)
		return (2);
	return (0);
}
