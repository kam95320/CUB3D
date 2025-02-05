/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:40:02 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/05 10:41:37 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

// bool	check_is_valid(char *arg)
// {
// 	if (false == check_is_cub_file(arg))
// 	{
// 		print_error("this is not a file.cub\n");
// 		return (false);
// 	}
// 	else if (false == check_is_xpm_file(arg))
// 	{
// 		print_error("this is not a file.xpm\n");
// 		return (false);
// 	}
// 	if (false == check_open(arg))
// 	{
// 		print_error("bad file descriptor\n");
// 		return (false);
// 	}
// 	return (true);
// }
bool	check_is_valid(char *arg)
{
	printf("DEBUG: Vérification de %s\n", arg);

	if (false == check_is_cub_file(arg))
	{
		printf("pass1\n\n\n");
		print_error("this is not a file.cub\n");
		return (false);
	}
	printf("DEBUG: Le fichier est un .cub\n");

	if (false == check_open(arg))
	{
		printf("pass2\n");
		print_error("bad file descriptor\n");
		return (false);
	}
	printf("DEBUG: Le fichier peut être ouvert\n");

	return (true);
}
