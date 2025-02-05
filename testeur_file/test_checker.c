/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:54:13 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/05 18:31:31 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/testeur.h"
#include <stdbool.h>
#include <stdio.h>

void free_map(char **map)
{
    if (!map)
        return;

    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);

    free(map);
}

void	run_test(char *filename, bool expected)
{
	bool	result;

	result = check_is_valid(filename);
	printf("Test avec fichier: '%s' -> %s (attendu: %s)\n", filename,
		result ? "VALIDE" : "INVALIDE", expected ? "VALIDE" : "INVALIDE");
	if (result != expected)
		printf("\033[1;31m[ÉCHEC] Test échoué pour: %s\033[0m\n", filename);
	else
		printf("\033[1;32m[SUCCÈS] Test réussi pour: %s\033[0m\n", filename);
}

int	main(int argc, char *argv[])
{
	t_minilib_window	mlx_data;
	two_d_t				two_d;

	// (void)argc;
	//  (void)argv;
	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	if (take_mem_map(&mlx_data, &two_d, argv[1]))
		printf("Memory map setup successful!\n");
	else
		printf("Memory map setup failed!\n");
	printf("=== Début des tests check_is_valid ===\n");
	run_test(argv[1], true);
	// run_test("../good_cub/folder.cub", true);
	// run_test("../good_cub/.cub", false);
	printf("\n=== Fin des tests check_is_valid ===\n\n");
	printf("=== Début des tests take_mem_map ===\n");
	printf("Lines counted: %d\n", mlx_data.map_data.line_len);
	printf("File path: %s\n", mlx_data.map_data.path);
	printf("File allocation: %s\n",
		(mlx_data.map_data.file != NULL) ? "Success" : "Failure");
	free(mlx_data.map_data.file);
	printf("=== fin des tests  take_mem_map ===\n\n");
	printf("\n=== debut des tests map_is_valid ===\n");
	 memset(&mlx_data, 0, sizeof(mlx_data));

    char **map = load_map_from_file(argv[1]);
    if (!map)
        return 1;

    if (map_is_valid(map, &mlx_data))
        printf("Map is valid ✅\n");
    else
        printf("Map is invalid ❌\n");

    free_map(map);
    
	
	printf("=== fin des tests map_is_valid ===\n\n");
	
	
	return (0);
}
