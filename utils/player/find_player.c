/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:53:41 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/25 20:27:12 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

char **find_map_start(char **map)
{
    int i = 0;

    
    while (map[i] && (map[i][0] == '\0' || map[i][0] == ' ' || (map[i][0] >= 'A' && map[i][0] <= 'Z')))
        i++;

    printf("✅ Détection du début du labyrinthe à la ligne [%d]: %s\n", i, map[i]);
    return (&map[i]);
}




// void find_player(t_player *player, char **map)
// {
//     int y = 0;
//     int x;

//     printf("\n🔍 Détection du joueur dans `find_player()`\n");

//     while (map[y])
//     {
//         x = 0;
//         while (map[y][x])
//         {
//             // printf("Checking map[%d][%d] = %c\n", y, x, map[y][x]); // Debug

//             if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
//             {
//                 player->fl_pl_pos_x = x + 0.5; // Centrage dans la case
//                 player->fl_pl_pos_y = y + 0.5;
//                 player->direction = map[y][x];

//                 // Définir la direction de la caméra
//                 if (map[y][x] == 'N') { player->cam_pos_x = 0; player->cam_pos_y = -1; }
//                 if (map[y][x] == 'S') { player->cam_pos_x = 0; player->cam_pos_y = 1; }
//                 if (map[y][x] == 'E') { player->cam_pos_x = 1; player->cam_pos_y = 0; }
//                 if (map[y][x] == 'W') { player->cam_pos_x = -1; player->cam_pos_y = 0; }

//                 printf("✅ Joueur détecté en (%.2f, %.2f) regardant %c\n",
//                         player->fl_pl_pos_x, player->fl_pl_pos_y, player->direction);
//                 return;
//             }
//             x++;
//         }
//         y++;
//     }
//     printf("⚠️ Erreur: Aucun joueur trouvé dans la carte !\n");
// }
