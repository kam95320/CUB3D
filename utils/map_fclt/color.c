/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:56:26 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/05 14:08:53 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

// static int	*rgb_is_number(char **s1, int *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i])
// 	{
// 		s2[i] = ft_atoi(s1[i]);
// 		if (s2[i] == -1)
// 		{
// 			print_error("is not an integer\n");
// 			free_tab((void **)s1);
// 			free(s2);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	free_tab((void **)s1);
// 	return (s2);
// }

int	valid_lli(long long int nt, char c, int sign, int situation)
{
	if (situation == 1)
		if (sign > 0 && ((nt > (LLONG_MAX - (c - 48)) / 10)
				|| (nt == (LLONG_MAX - (c - 48)) / 10
					&& c - 48 > LLONG_MAX % 10)))
			return (0);
	if (situation == 2)
		if (sign < 0 && ((nt > (LLONG_MIN + (c - 48)) / (-10))
				|| (nt == (LLONG_MIN + (c - 48)) / (-10)
					&& c - 48 > LLONG_MIN % 10 * (-1))))
			return (0);
	return (1);
}

int	check_lli(char *str)
{
	long long int	nt;
	int				i;
	int				sign;

	i = 0;
	nt = 0;
	sign = 1;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (!valid_lli(nt, str[i], sign, 1))
			return (0);
		if (!valid_lli(nt, str[i], sign, 2))
			return (0);
		nt = nt * 10 + (str[i] - 48);
		i++;
	}
	if (str[i])
		return (0);
	return (1);
}

static	int	rgb_check(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i] && str[i + 1])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	if (!check_lli(str) || (ft_atoi(str) < 0 || ft_atoi(str) > 255))
		return (0);
	return (1);
}
// static char	**count_str(char **tab, char *mp)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	while (mp[i] == 32 || mp[i] == 'C' || mp[i] == 'F')
// 		i++;
// 	str = i + mp;
// 	tab = ft_split(str, ',');
// 	i = 0;
// 	while (tab[i])
// 		i++;
// 	if (i != 3)
// 	{
// 		print_error("rgb file not 3\n");
// 		free_tab((void **)tab);
// 		return (0);
// 	}
// 	return (tab);
// }

// static int	*rgb(char *mp)
// {
// 	char	**tab;
// 	int		*str;
// 	int		*result;

// 	tab = count_str(NULL, mp);
// 	if (!tab)
// 		return (NULL);
// 	str = malloc(sizeof(int) * 3);
// 	if (!str)
// 	{
// 		print_error("rgb malloc * 3 in rgb  failed\n");
// 		free_tab((void **)tab);
// 		return (NULL);
// 	}
// 	result = rgb_is_number(tab, str);
// 	if (!result)
// 	{
// 		free(str);
// 		return (NULL);
// 	}
// 	return (result);
// }

int	tstrcmp(char *str, char *cmp)
{
	int	i;

	i = -1;
	while (str && cmp && (str[++i] || cmp[i]))
		if (str[i] != cmp[i])
			return (str[i] - cmp[i]);
	return (0);
}
void	fill_floor(t_cub *cub, char *line)
{
	char	**rgb;
	char	*floor;

	rgb = ft_split(line, ' ');
	if (tstrcmp(rgb[0], "F") || !rgb[1])
	{
		fsplit(rgb);
		wgas(cub, "First lines should contain Floor and Ceiling RGB colors\n", NULL);
	}
	floor = erase_new_line(rgb[1]);
	fsplit(rgb);
	rgb = ft_split(floor, ',');
	free(floor);
	if (!rgb || (!(rgb[0] && rgb[1] && rgb[2]))
		|| (!rgb_check(rgb[0]) || !rgb_check(rgb[1]) || !rgb_check(rgb[2])))
	{
		fsplit(rgb);
		wgas(cub, "floor", "invalid rgb value");
	}
	cub->map->floor = malloc(sizeof(t_rgb));
	if (!cub->map->floor)
		return (freend(cub));
	cub->map->floor->r = ft_atoi(rgb[0]);
	cub->map->floor->g = ft_atoi(rgb[1]);
	cub->map->floor->b = ft_atoi(rgb[2]);
	fsplit(rgb);
}


void	fill_ceiling(t_cub *cub, char *line)
{
	char	**rgb;
	char	*ceiling;

	rgb = ft_split(line, ' ');
	if (!rgb || tstrcmp(rgb[0], "C") || !rgb[1])
	{
		fsplit(rgb);
		wgas(cub, "First lines should contain floor and Ceiling RGB colors\n", NULL);
	}
	ceiling = erase_new_line(rgb[1]);
	fsplit(rgb);
	rgb = ft_split(ceiling, ',');
	free(ceiling);
	if (!rgb || (!(rgb[0] && rgb[1] && rgb[2]))
		|| (!rgb_check(rgb[0]) || !rgb_check(rgb[1]) || !rgb_check(rgb[2])))
	{
		fsplit(rgb);
		wgas(cub, "ceiling", "invalid rgb value");
	}
	cub->map->ceiling = malloc(sizeof(t_rgb));
	if (!cub->map->ceiling)
		return (freend(cub));
	cub->map->ceiling->r = ft_atoi(rgb[0]);
	cub->map->ceiling->g = ft_atoi(rgb[1]);
	cub->map->ceiling->b = ft_atoi(rgb[2]);
	fsplit(rgb);
}

void	fccolors(t_cub *cub)
{
	char	*line;

	line = get_next_line(cub->fd);
	while (line && (!cub->map->floor || !cub->map->ceiling))
	{
		if (!null_line(line))
		{
			if (line[0] && line[0] == 'F')
				fill_floor(cub, line);
			else if (line[0] && line[0] == 'C')
				fill_ceiling(cub, line);
			else
				break ;
		}
		free(line);
		if ((cub->map->floor && cub->map->ceiling))
			break ; 
		line = get_next_line(cub->fd);
	}
	if (!cub->map->floor || !cub->map->ceiling)
		wgas(cub, "fccolors",
			"First lines should contain address Floor and ceiling value");

}
