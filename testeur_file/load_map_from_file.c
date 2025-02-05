/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:35:40 by kahoumou          #+#    #+#             */
/*   Updated: 2025/02/05 17:36:20 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/testeur.h"

char	**load_map_from_file(const char *filename)
{
	FILE *file = fopen(filename, "r");
	if (!file)
	{
		print_error("Unable to open map file.");
		return (NULL);
	}

	char **map = malloc(100 * sizeof(char *));
		// Supposons un maximum de 100 lignes
	if (!map)
	{
		print_error("Memory allocation failed.");
		fclose(file);
		return (NULL);
	}

	size_t len = 0;
	ssize_t read;
	char *line = NULL;
	int i = 0;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line[strcspn(line, "\n")] = '\0'; // Supprime le \n à la fin de la ligne
		map[i] = strdup(line);
		i++;
	}

	map[i] = NULL; // Terminaison du tableau
	fclose(file);
	free(line);
	return (map);
}