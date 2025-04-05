/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:48:46 by kahoumou          #+#    #+#             */
/*   Updated: 2025/04/03 15:33:24 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

bool	check_open(char *file)
{
	int	fd;
	
	printf("file = %s\n", file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		print_error("DEBUG: Échec de l'ouverture de %s\n");
		return (false);
	}
	close(fd);
	return (true);
}
