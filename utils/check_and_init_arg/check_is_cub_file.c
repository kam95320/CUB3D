/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_cub_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:31:27 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/03 16:36:45 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

bool	check_is_cub_file(char *file)
{
	size_t	file_s;

	file_s = ft_strlen(file);
	if (file[file_s - 4] == '.' && file[file_s - 3] == 'b' && file[file_s
			- 2] == 'u' && file[file_s - 1] == 'c')
	{
		return (true);
	}
	return (false);
}
