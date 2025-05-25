/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_cub_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:31:27 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/22 13:27:36 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

bool	check_is_cub_file(char *file)
{
	size_t	file_s;

	file_s = ft_strlen(file);
	if (file_s < 4)
		return (false);
	if (file[file_s - 5] == '/')
		return (false);
	if (file[file_s - 4] == '.' && file[file_s - 3] == 'c' && file[file_s
			- 2] == 'u' && file[file_s - 1] == 'b')
	{
		return (true);
	}
	return (false);
}
