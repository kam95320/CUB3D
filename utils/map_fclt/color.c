/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:56:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/11 17:18:33 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

static int	*rgb_is_number(char **s1, int *s2)
{
	int	i;

	printf("rgb_is_number deb =  s1[0] =  %s, s1[1] =  %s, s2[2] = %s\n", s1[0],
		s1[1], s1[2]);
	i = 0;
	while (s1[i])
	{
		printf("in rgb  is  number while %d\n", i);
		s2[i] = ft_atoi(s1[i]);
		// printf("in rgb  is  number s2 =  %d\n", s2[i]);
		// if (s2[i] == -1 || ft_isdigit(s2[i]) != 2048)
		// {
		// 			printf("in rgb is number free\n");
		// 	free_tab((void **)s1);
		// 	free(s2);
		// 	return (0);
		// }
		i++;
	}
	// printf("rgb_is_number end\n\n");
	free_tab((void **)s1);
	return (s2);
}

static char	**count_str(char **tab, char *mp)
{
	int		i;
	char	*str;

	i = 0;
	while (mp[i] == 32 || mp[i] == 'C' || mp[i] == 'F')
		i++;
	str = i + mp;
	printf("pass in count_str | mp =  %s\n\n", str);
	tab = ft_split(str, ',');
	printf("tab after split | tab[0] = %s, tab[1] =  %s, tab[2]  = %s \n",
		tab[0], tab[1], tab[2]);
	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
	{
		print_error("rgb file not 3\n");
		free_tab((void **)tab);
		return (0);
	}
	printf("pass in end of count_str\n\n");
	return (tab);
}

static int	*rgb(char *mp)
{
	char	**tab;
	int		*str;
	int		*result;

	printf("pass  in deb fonction rgb\n\n");
	printf("pass  in rgb | mp  = %s\n", mp);
	tab = count_str(NULL, mp);
	if (!tab)
		return (NULL);
	str = malloc(sizeof(int) * 3);
	if (!str)
	{
		printf("pass  in rgb malloc * 3\n");
		free_tab((void **)tab);
		return (NULL);
	}
	result = rgb_is_number(tab, str);
	printf("pass  after rgb result\n");
	// free_tab((void **)tab);
	// if (!result)
	// {
	// 	free(str);
	// 	return (NULL);
	// }
	printf("pass  in end fonction rgb = %ls\n\n", result);
	return (result);
}

// bool	color(t_info_texture *txt, char *mp, char ltr)
// {
// 	printf("pass in color ltr =  %c\n\n", ltr);
// 	if (ltr == 'C' || ltr == 'F')
// 	{
// 			printf("pass in color =  %s\n\n", mp);
// 		if (ltr ==  'C')
// 		{
// 			printf("pass C\n");
// 			txt->ceiling = rgb(mp);
// 		}
// 		if (ltr ==  'F')
// 		{
// 			printf("pass F\n");
// 			txt->floor = rgb(mp);
// 		}
// 		if (!txt->ceiling || !txt->floor)
// 		{
// 			print_error("ERROR: Ceiling or floor RGB values are not set.\n");
// 			return (false);
// 		}
// 		hx_txt(txt, 'F');
// 		hx_txt(txt, 'C');
// 		printf("Floor: %d, %d, %d\n", txt->floor[0], txt->floor[1],
// 			txt->floor[2]);
// 		printf("Ceiling: %d, %d, %d\n", txt->ceiling[0], txt->ceiling[1],
// 				txt->ceiling[2]);
// 	}
// 	return (true);
// }

bool	color(t_info_texture *txt, char *mp, char ltr)
{
	printf("pass in color ltr =  %c\n\n", ltr);
	if (ltr == 'C' || ltr == 'F')
	{
		printf("pass in color =  %s\n\n", mp);
		// On passe les valeurs sans le 'F ' ou 'C '
		if (ltr == 'C')
		{
			printf("pass C\n");
			txt->ceiling = rgb(mp + 2);
			printf("after rgb txt->ceiling =  %p\n", txt->ceiling);
			printf("DEBUG: txt->ceiling assigned: %p -> [%d, %d, %d]\n",
				(void *)txt->ceiling, txt->ceiling[0], txt->ceiling[1],
				txt->ceiling[2]);
		}
		if (ltr == 'F')
		{
			printf("pass F\n");
			txt->floor = rgb(mp + 2);
			printf(" after rgb txt->floor =  %p\n", txt->floor);
		}
		printf("DEBUG: txt->floor assigned: %p -> [%d, %d, %d]\n",
			(void *)txt->floor, txt->floor[0], txt->floor[1], txt->floor[2]);
		// Vérification des valeurs affectées
		if (!txt->ceiling && !txt->floor)
		{
			print_error("ERROR: Ceiling or floor RGB values are not set.\n");
			return (false);
		}
		// Debug : vérifier les valeurs stockées
		// printf("Floor: %d, %d, %d\n", txt->floor[0], txt->floor[1],
		// 	txt->floor[2]);
		// printf("Ceiling: %d, %d, %d\n", txt->ceiling[0], txt->ceiling[1],
		// 	txt->ceiling[2]);
	}
	return (true);
}
