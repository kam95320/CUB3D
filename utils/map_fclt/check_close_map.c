/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_close_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:13:18 by kahoumou          #+#    #+#             */
/*   Updated: 2025/05/28 16:09:56 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

bool	check_dir(char dir)
{
	if (dir == 'N')
	{
		return (true);
	}
	else if (dir == 'S')
	{
		return (true);
	}
	else if (dir == 'E')
	{
		return (true);
	}
	else if (dir == 'W')
	{
		return (true);
	}
	return (false);
}

static void	write_edge_of_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		printf(GREEN " %c" RESET, line[i]);
		if ((line[i] != '0' || line[i] != '1') && line[i + 1] == '\n')
		{
			printf(RED " %c" RESET, line[i]);
			printf(ORANGE "-> out of map" RESET);
		}
		i++;
	}
}

static void	write_line_not_close(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		printf(GREEN " %c" RESET, line[i]);
		if (line[i] == '0' && line[i + 1] == '\n')
			printf(RED " %c" RESET, line[i]);
		i++;
	}
}

bool	player_outside_map(char **map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map[y])
	{
		i = 0;
		while (((map[y][i]) && (map[y][i] == '0' || map[y][i] == '1'))
			|| check_dir(map[y][i]))
		{
			if (check_dir(map[y][i]) && (map[y][i + 1] == '\n' || map[y][i
					+ 1] == '\0'))
			{
				printf(YELLOW "->Plyaer on the edge of the void <-\n" RESET);
				printf(CYAN " line  = [%d] | case = [%d]\n" RESET, y, i);
				write_edge_of_map(map[y]);
				printf(RED "[ERROR MAP IS NOT CLOSE]\n" RESET);
				return (false);
				i++;
			}
			i += 1;
		}
		y += 1;
	}
	return (true);
}
static bool	found_mystake(char **map, int y, int i)
{
	while (map[y][i] != '\n')
	{
		if (map[y][i] == '0' && map[y][i + 1] == '\n')
			return (false);
		// if (map[y][1] == '0')
		// 	return (false);
		// if (map[y + 1] ==  NULL && map[y][i] == '0')
		// 	return (false);
		i ++;
	}
	return(true);
}
bool	check_close_map(char **map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map[y])
	{
		i = 0;
		while (((map[y][i]) && (map[y][i] == '0' || map[y][i] == '1'))
			|| (check_dir(map[y][i])))
		{
			if (found_mystake(map, y, i)  == false)
			{
				printf(LIGHT_BLUE "->BINARY LINE  WITH  ERROR <-\n" RESET);
				printf(CYAN " line  = [%d] | case = [%d]\n" RESET, y, i);
				write_line_not_close(map[y]);
				printf(RED "[ERROR MAP IS NOT CLOSE]\n" RESET);
				return (false);
				i++;
			}
			i += 1;
		}
		y += 1;
	}
	return (true);
}
