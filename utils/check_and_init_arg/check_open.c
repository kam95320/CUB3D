/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:48:46 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/04 14:16:28 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

// bool	check_open(char *file)
// {
// 	int	fd;

// 	fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		return (false);
// 	}
// 	close(fd);
// 	return (true);
// }


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

bool	check_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("DEBUG: Erreur ouverture fichier");
		printf("DEBUG: Échec de l'ouverture de %s\n", file);
		return (false);
	}

	printf("DEBUG: Fichier %s ouvert avec succès (fd = %d)\n", file, fd);
	close(fd);
	return (true);
}
