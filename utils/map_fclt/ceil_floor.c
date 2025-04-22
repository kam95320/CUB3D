/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:32:43 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/22 13:55:11 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	valid_lli(long long int nt, char c, int sign, int situation)
{
	if (situation == 1)
		if (sign > 0 && ((nt > (LLONG_MAX - (c - 48)) / 10) || (nt == (LLONG_MAX
						- (c - 48)) / 10 && c - 48 > LLONG_MAX % 10)))
			return (0);
	if (situation == 2)
		if (sign < 0 && ((nt > (LLONG_MIN + (c - 48)) / (-10))
				|| (nt == (LLONG_MIN + (c - 48)) / (-10) && c - 48 > LLONG_MIN
					% 10 * (-1))))
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

static int	rgb_check(char *str)
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

void	fill_floor(t_cub *cub, char *line)
{
	char	**rgb;
	char	*floor;

	rgb = ft_split(line, ' ');
	if (tstrcmp(rgb[0], "F") || !rgb[1])
	{
		fsplit(rgb);
		wgas(cub, "First lines should contain Floor and Ceiling RGB colors\n",
			NULL);
	}
	floor = erase_new_line(rgb[1]);
	fsplit(rgb);
	rgb = ft_split(floor, ',');
	free(floor);
	if (!rgb || (!(rgb[0] && rgb[1] && rgb[2])) || (!rgb_check(rgb[0])
			|| !rgb_check(rgb[1]) || !rgb_check(rgb[2])))
	{
		fsplit(rgb);
		wgas(cub, "floor", "invalid rgb value");
	}
	cub->map->floor = malloc(sizeof(t_rgb));
	if (!cub->map->floor)
		return (freend(cub));
	rgb_nb_convert(cub, rgb, 'f');
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
		wgas(cub, "First lines should contain floor and Ceiling RGB colors\n",
			NULL);
	}
	ceiling = erase_new_line(rgb[1]);
	fsplit(rgb);
	rgb = ft_split(ceiling, ',');
	free(ceiling);
	if (!rgb || (!(rgb[0] && rgb[1] && rgb[2])) || (!rgb_check(rgb[0])
			|| !rgb_check(rgb[1]) || !rgb_check(rgb[2])))
	{
		fsplit(rgb);
		wgas(cub, "ceiling", "invalid rgb value");
	}
	cub->map->ceiling = malloc(sizeof(t_rgb));
	if (!cub->map->ceiling)
		return (freend(cub));
	rgb_nb_convert(cub, rgb, 'c');
	fsplit(rgb);
}
