/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_mn_mp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:17:59 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/12 19:02:29 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void pix_img(t_manip_img *image, int x, int y, int color)
{
    int pixel;

    pixel = y * (image->size_of_line / 4) + x;
    image->pixel_img[pixel] = color;
}

static void set_minimap_border_image_pixels(t_minimap *minimap, int color)
{
    int size;
    int x;
    int y;

    size = PIXEL_SIZE + minimap->mn_mp_case_size;
    y = 0;
    while (y < size)
    {
        x = 0;
        while (x <= size)
        {
            if (x < 5 || x > size - 5 || y < 5 || y > size - 5)
                pix_img(minimap->mini_img, x, y, color);
            x++;
        }
        y++;
    }
}


static void mnp_pix(t_minimap *minimap, int x, int y, int color)
{
    int i;
    int j;

    i = 0;
    while (i < minimap->mn_mp_case_size)
    {
        j = 0;
        while (j < minimap->mn_mp_case_size)
        {
            pix_img(minimap->mini_img, x + j, i + y, color);
            j++;
        }
        i++;
    }
}
 
static void draw_minimap(t_minimap *minimap)
{
    int x;
    int y;

    y = 0;
    while (y < minimap->mini_mp_size)
    {
        x = 0;
        while (x < minimap->mini_mp_size)
        {
            if (!minimap->mini_mp[y] || !minimap->mini_mp[y][x]
                || minimap->mini_mp[y][x] == '\0')
                break;
            mn_title(minimap, x, y);
            x++;
        }
        y++;
    }
    set_minimap_border_image_pixels(minimap, COLOR_SPACE);
}

static void mn_title(t_minimap *minimap, int x, int y)
{
    if (minimap->mini_mp[y][x] == 'P')
        mnp_pix(minimap, x * minimap->mn_mp_case_size,
            y * minimap->mn_mp_case_size, COLOR_PLAYER);
    else if (minimap->mini_mp[y][x] == '1')
        mnp_pix(minimap, x * minimap->mn_mp_case_size,
            y * minimap->mn_mp_case_size, COLOR_WALL);
    else if (minimap->mini_mp[y][x] == '0')
        mnp_pix(minimap, x * minimap->mn_mp_case_size,
            y * minimap->mn_mp_case_size, COLOR_FLOOR);
    else if (minimap->mini_mp[y][x] == ' ')
        mnp_pix(minimap, x * minimap->mn_mp_case_size,
            y * minimap->mn_mp_case_size, COLOR_SPACE);
}



void put_img_mnp(t_minilib_window *win, t_minimap *minimap)
{
    int img_size;

    img_size = PIXEL_SIZE + minimap->mn_mp_case_size;
    init_mnp(win, &win->minimap_info.mini_img, img_size, img_size);
    draw_minimap(minimap);
    mlx_put_image_to_window(win->mlx_connex, win->window, win->minimap_info.mini_img->ptr_img,
        minimap->mn_mp_case_size, win->size_width - (PIXEL_SIZE + (minimap->mn_mp_case_size * 2)));
    mlx_destroy_image(win->mlx_connex, win->minimap_info.mini_img->ptr_img);
}

