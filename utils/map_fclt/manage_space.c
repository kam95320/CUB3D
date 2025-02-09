/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:02:33 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/09 18:52:27 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	skip_space(char **mp, int i, int len)
{
	printf("pass in skip_space (i=%d, len=%d, char='%c')\n", i, len,
		mp[i][len]);
	if (!mp || !mp[i])
		return (len);
	while (mp[i][len] == ' ' || mp[i][len] == '\t')
		len++;
	return (len);
}

int	manage_txt_space(char *stc, int len, int cond)
{
	printf("pass in manage_txt_space\n");
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
