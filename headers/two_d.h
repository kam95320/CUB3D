/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:41:04 by kahoumou          #+#    #+#             */
/*   Updated: 2025/01/13 14:37:42 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWO_D_H
# define TWO_D_H
# include <unistd.h>

typedef struct two_d_s
{
	int		row;
	int		i;
    char *line;
	size_t	col;
}			two_d_t;
#endif