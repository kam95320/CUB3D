/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:17:59 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/26 16:07:24 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
typedef struct s_map
{
	char	*path;
	char	**file;
	int		fd;
	int		line_len;
	int		height;
	int		width;
	int		map_ending;
	int		zoom;

}			t_map;

typedef struct s_valid
{
	int		i;
	int		j;

}			t_valid;

#endif // MAP_H