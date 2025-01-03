/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:40:02 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/03 16:25:04 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

bool	check_is_valid(char *arg)
{
	if (false == check_is_cub_file(arg))
	{
		print_error("this is not a file.cub\n");
		return (false);
	}
	if (false == check_is_xpm_file(arg))
	{
		print_error("this is not a file.xpm\n");
		return (false);
	}
	if (false == check_open(arg))
	{
		print_error("bad file descriptor\n");
		return (false);
	}
	return (true);
}
