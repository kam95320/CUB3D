/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_xpm_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:11 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/03 16:35:23 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

bool	check_is_xpm_file(char *file)
{
	size_t	file_size;

	file_size = ft_strlen(file);
	if (file[file_size - 4] == '.' && file[file_size - 3] == 'm'
		&& file[file_size - 2] == 'p' && file[file_size - 1] == 'x')
	{
		return (true);
	}
	return (false);
}
