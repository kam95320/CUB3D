/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:54:13 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/04 14:24:34 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/testeur.h"
#include <stdbool.h>
#include <stdio.h>

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
	(void)argc;
	printf("=== Début des tests ===\n\n");
	run_test(argv[1], true);
	// run_test("map_valid.txt", true);
	// run_test("image.xpm", false);
	// run_test("inexistant.cub", false);
	// run_test("map_sans_extension", false);
	// run_test(".cub", false);
	// run_test("map_invalid.cub.txt", false);
	printf("\n=== Fin des tests ===\n");
	return (0);
}
