/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 01:05:10 by tespandj          #+#    #+#             */
/*   Updated: 2025/04/22 17:30:53 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	null_line(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (!((str[i] >= 8 && str[i] <= 12) || str[i] == ' '))
			return (0);
	return (1);
}

void	fsplit(char **str)
{
	int	i;

	i = -1;
	if (str)
	{
		while (str[++i])
			free(str[i]);
		free(str);
	}
}

void	gnl_free(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (fd > 0)
		close(fd);
}

char	*erase_new_line(char *str)
{
	char	*line;
	int		i;

	i = -1;
	line = malloc(sizeof(char) * ft_strlen(str));
	if (!line)
		return (NULL);
	while (str && str[++i] && str[i + 1])
		line[i] = str[i];
	line[i] = '\0';
	return (line);
}

int	end_win(t_cub *cub)
{
	mlx_destroy_image(cub->data->mlx, cub->data->img);
	mlx_destroy_window(cub->data->mlx, cub->data->win);
	mlx_destroy_display(cub->data->mlx);
	free(cub->data->mlx);
	freend(cub);
	exit(0);
}
