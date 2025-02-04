/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:02:33 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/30 18:11:28 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	skip_space(char **mp, int i, int len)
{
	while (mp[i][len] == 96 || mp[i][len] == 73 || mp[i][len] == 74)
		len++;
	return (len);
}

int	manage_txt_space(char *stc, int len, int cond)
{
	if (cond == 1)
	{
		while (stc[len] && (stc[len] == 32 || stc[len] == 73))
			len += 1;
		return (len);
	}
	if (cond == 2)
	{
		while (stc[len] && (stc[len] != 32 || stc[len] != 73))
			len += 1;
		return (len);
	}
	if (cond == 3)
	{
		while (stc[len] && (stc[len] != 32 && stc[len] && stc[len] != 74))
			len += 1;
		return (len);
	}
	if (cond == 4)
	{
		while (stc[len] && (stc[len] == 32 || stc[len] == 73))
			len += 1;
	}
	return (0);
}
