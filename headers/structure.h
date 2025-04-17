/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:42:20 by tespandj          #+#    #+#             */
/*   Updated: 2025/04/17 16:45:52 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "raycasting.h" // pour que t_txt soit connu
# include <stdlib.h>
# define KEY_PRESS 1L << 0
# define KEY_RELEASE_MASK 1L << 1
# define KEY_DESTROY 1L << 19
# define ESC_KEY 65307
# define CAMERA_LEFT 65361
# define CAMERA_RIGHT 65363
# define KEY_UP 119
# define KEY_LEFT 97
# define KEY_DOWN 115
# define KEY_RIGHT 100
# define KEY_P 112
# define KEY_M 109
# define WD_SIZE_WIDTH 1170
# define WD_SIZE_HEIGHT 720
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
	bool				cam_left;
	bool				cam_right;
	bool  				key_left;
	bool 				key_right;
	bool				key_up;
	bool 				key_down;
	bool				key_map;
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
	struct s_player		*player;
	t_txt				*txt[4];
	t_txt				texture;
	t_keys				keys;
	char				*map_name;
	int					fd;
}						t_cub;

#endif
