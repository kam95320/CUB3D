/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:23:18 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/05 18:15:58 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTEUR_H
    #define TESTEUR_H
      #include"utils.h"
      #include <string.h>
      #include <stdbool.h>
      bool	check_is_valid(char *arg);
      char	**load_map_from_file(const char *filename);
    
      
      
      
#endif