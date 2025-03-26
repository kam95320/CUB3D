/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:45:08 by kahoumou          #+#    #+#             */
/*   Updated: 2025/03/26 17:44:21 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# define TEXTURE_SIZE 64
typedef struct s_manip_img
{
	void			*ptr_img;
	int				*pixel_img;
	int				**pix_mem_texture;
	int				pix_img;
	int				size_of_line;
	int				oct_indian;

}					t_manip_img;
typedef struct s_map_data
{
	char			**matrix;
	int				L;
	int				l;
	t_rgb			*floor;
	t_rgb			*ceiling;
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
}					t_map_data;
typedef struct s_info_texture
{
	char			*direct_north;
	char			*direct_south;
	char			*direct_west;
	char			*direct_east;
	unsigned long	hxd_floor;
	unsigned long	hxd_ceiling;
	int				*floor;
	int				*ceiling;
	int				texture_size;
	double			step_by_step;
	double			position;
	int				x;
	int				y;
	int				red;
	int				green;
	int				blue;
}					t_info_texture;

#endif