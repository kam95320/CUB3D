/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:36:18 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/12 18:48:13 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"


static void initialzation_mlx(t_minilib_window *data)
{
    data->mlx_connex = mlx_init;
    if(!data->mlx_connex)
        print_error("mlx initializtion error\n");
    data->window  =  mlx_new_window;
    if(!data->window)
            print_error("mlx new_window error\n");
    
    
        
} 