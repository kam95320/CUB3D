/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:02:33 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/22 18:49:35 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	skip_space(char **mp, int i, int j)
{
	while (mp[i][j] == 140 || mp[i][j] == 73 || mp[i][j] == 74)
		j++;
}

void	skip_txt_space(char *stc, int j)
{
	int sz;
	sz = 0;
	while (stc[j] && (stc[j] == 32 || stc[j] == 73))
		j += 1;
	sz = j;
	while (stc[j] && (stc[sz] != 32 && stc[sz]) == 73)
		sz += 1;
   
}