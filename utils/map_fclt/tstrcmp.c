/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstrcmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:29:21 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/21 17:30:08 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"


int	tstrcmp(char *str, char *cmp)
{
	int	i;

	i = -1;
	while (str && cmp && (str[++i] || cmp[i]))
		if (str[i] != cmp[i])
			return (str[i] - cmp[i]);
	return (0);
}