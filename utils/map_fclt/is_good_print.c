/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_good_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:57:14 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/10 15:49:00 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

static int	txt_cond(char **mp, int i, int j)
{
	while (mp[i][j] == ' ' || mp[i][j] == '\t')
		j++;
	if (!mp[i][j] || !mp[i][j + 1])
		return (0);
	if (mp[i][j] == 'N' && mp[i][j + 1] == 'O')
		return (1);
	if (mp[i][j] == 'S' && mp[i][j + 1] == 'O')
		return (2);
	if (mp[i][j] == 'W' && mp[i][j + 1] == 'E')
		return (3);
	if (mp[i][j] == 'E' && mp[i][j + 1] == 'A')
		return (4);
	return (0);
}

static char	*pth_txt(char *mp, int j)
{
	int		len;
	char	*str;

	j = manage_txt_space(mp, j, 1);
	len = manage_txt_space(mp, j, 2) - j;
	if (len <= 0)
		return (NULL);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, mp + j, len + 1);
	str[len] = '\0';
	 printf("DEBUG pth_txt: Extracted path: `%s`\n", str);
	return (str);
}

static void	vl_direct(t_info_texture *txt, char *mp, int j, int t_c)
{
	printf("DEBUG vl_direct: t_c=%d, extracting from: %s\n", t_c, mp + j + 2);
	if (t_c == 1 && !txt->direct_north)
		txt->direct_north = pth_txt(mp, j + 2);
	if (t_c == 2 && !txt->direct_south)
		txt->direct_south = pth_txt(mp, j + 2);
	if (t_c == 3 && !txt->direct_west)
		txt->direct_west = pth_txt(mp, j + 2);
	if (t_c == 4 && !txt->direct_east)
		txt->direct_east = pth_txt(mp, j + 2);
	printf("DEBUG After vl_direct: NO=%s, SO=%s, WE=%s, EA=%s\n",
		txt->direct_north, txt->direct_south, txt->direct_west,
		txt->direct_east);
	printf("North: %s\n", txt->direct_north);
	printf("South: %s\n", txt->direct_south);
	printf("West:  %s\n", txt->direct_west);
	printf("East:  %s\n", txt->direct_east);
}
char tk_ltr_F_C(char *ltr)
{
	int i;
	i = 0;
	printf("ltr in tk_ltr_F_C = %s\n\n", ltr);
	while(ltr[i])
	{
		if(ltr[i] ==  'F')
		{
			printf("F = %c\n", ltr[i]);
			return('F');
		}
		if(ltr[i] ==  'C')
		{
			printf("C = %c\n", ltr[i]);
			return('C');
		}
		i ++;
	}
	
	return(ltr[i]);
}
bool	is_good_print(t_info_texture *txt, char **mp, int i, int j)
{
	int	val;
	int	t_c;
	char ltr = tk_ltr_F_C(&mp[j][0]);
	printf("pass in is_good_print\n");
	t_c = txt_cond(mp, i, j);
	val = false;
	if (mp[i][j] == '0' || mp[i][j] == '1' || mp[i][j] == 'N' || mp[i][j] == 'S'
		|| mp[i][j] == 'W' || mp[i][j] == 'E')
	{
		val = true;
	}
	if (val && t_c != 0)
		vl_direct(txt, mp[i], j, t_c);
	printf("F = %s | C = %s\n\n\n", &mp[j][0], &mp[j][0]);
	if (ltr == 'F' || ltr == 'C')
			val = color(txt, mp[j + 1], ltr);
	printf("DEBUG color: i=%d, j=%d, char=%s\n", i, j, mp[j]);
	return (val);
}
