/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_or_ceiling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:04:53 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/12 19:11:03 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../../headers/utils.h"

int	floor_or_ceiling(char lt, t_info_texture *txt)
{
	printf("ceiling = %ls\n", txt->ceiling);
	printf("floor = %ls\n", txt->floor);
	if (lt == 'C')
	{
		return (1);
	}
	if (lt == 'F')
	{
		return (2);
	}
	return (0);
}
