/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_or_ceiling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:04:53 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/11 12:08:36 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../../headers/utils.h"

int	floor_or_ceiling(char lt, t_info_texture *txt)
{
	// printf("pass floor_or_ceiling deb =  %c\n", lt);
	printf("ceiling = %ls\n",  txt->ceiling);
	printf("floor = %ls\n",  txt->floor);
	
	if (lt == 'C')
	{
		return (1);
	}
	if (lt == 'F')
	{
		// printf("floor vaulue = %ls\n",  txt->floor);
		return (2);
	}
	// printf("pass floor_or_ceiling end\n\n");
	
	return (0);
}
