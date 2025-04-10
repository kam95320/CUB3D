/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:42:20 by tespandj          #+#    #+#             */
/*   Updated: 2025/04/09 18:29:20 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "raycasting.h" // pour que t_txt soit connu
# include <stdlib.h>
typedef struct s_txt	t_txt;

typedef struct s_keys
{
	int					w;
	int					a;
	int					s;
	int					d;
	int					l;
	int					r;
	int					q;
}						t_keys;

typedef struct spt
{
	const char			*str;
	char				**split;
	char				c;
	int					nb_words;
	int					indic;
	int					len;
	int					op;
	int					i;
}						t_split;

typedef struct s_rgb
{
	int					r;
	int					g;
	int					b;
}						t_rgb;

typedef struct s_map_data
{
	char				**matrix;
	int					L;
	int					l;
	t_rgb				*floor;
	t_rgb				*ceiling;
	int					floor_cl_hx;
	int					ceiling_cl_hx;
}						t_map_data;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					width;
	int					height;
	int					endian;
	int					bits_per_pixel;
	int					line_length;
	int					x_off;
	int					y_off;
}						t_data;

typedef struct s_cub
{
	struct s_map_data	*map;
	struct s_cam		*cam;
	struct s_data		*data;
	struct s_ray		*ray;
	t_txt				*txt[4];

	t_keys				keys;
	char				*map_name;
	int					fd;
}						t_cub;

#endif
