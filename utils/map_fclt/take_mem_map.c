/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_mem_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:42:13 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/12 17:11:50 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/two_d.h"
#include "../../headers/utils.h"

bool	take_mem_map(t_minilib_window *mlx_data, two_d_t *two_d, char *mp)
{
	printf("pass in  take_mem_map\n");
	int	data_sentences;
	
	data_sentences = 0;
	mlx_data->map_data.line_len = nb_line(mp);
	data_sentences = mlx_data->map_data.line_len;
	mlx_data->map_data.path = mp;
	mlx_data->map_data.file = ft_calloc(data_sentences + 1, sizeof(char *));
	
	printf("Nombre de lignes du fichier : %d\n", data_sentences);

	if (0 == (mlx_data->map_data.file))
	{
		print_error("problem with memory map data\n");
		return (false);
	}
	mlx_data->map_data.fd = open(mp, O_RDONLY);
	if (mlx_data->map_data.fd < 0)
	{
		print_error("probleme with fd map\n");
		return (false);
	}
	printf("Avant l'appel à completed_2d\n");
	completed_2d(two_d, mlx_data);
	printf("Après l'appel à completed_2d\n");
	close(mlx_data->map_data.fd);
	printf("take_mem_map end\n");
	return (true);
}
