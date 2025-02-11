/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:02:33 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/11 18:02:09 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	skip_space(char **mp, int i, int len)
{
	if (!mp || !mp[i])
		return (len);
	while (mp[i][len] == ' ' || mp[i][len] == '\t')
		len++;
	return (len);
}

int	manage_txt_space(char *stc, int len, int cond)
{
	if (cond == 1)
	{
		while (stc[len] && (stc[len] == ' ' || stc[len] == 'I'))
			len++;
		return (len);
	}
	if (cond == 2)
	{
		while (stc[len] && (stc[len] != ' ' && stc[len] != 'I'))
			len++;
		return (len);
	}
	if (cond == 3)
	{
		while (stc[len] && stc[len] != ' ' && stc[len] != 'J')
			len++;
		return (len);
	}
	if (cond == 4)
	{
		while (stc[len] && (stc[len] == ' ' || stc[len] == 'I'))
			len++;
		return (len);
	}
	return (0);
}
