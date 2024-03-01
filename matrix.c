/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:09:50 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/01 06:33:36 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void printhere(char **str)
{
	int i = -1;
	while (str[++i])
		printf("%s$\n", str[i]);
	return ;
}

char **get_matrix(int fd, int counter, char **map)
{
    char    *line;

    line = get_next_line(fd);
    if (line)
        map = get_matrix(fd, counter + 1, map);
    if (!map)
        map = malloc(sizeof(char *) * (counter + 1));
    map[counter] = line;
    return (map);
}

// attention: the width and height values do not match indexes.
// to get the maximum index, subtract 1
int is_rect(t_game *game, char **map)
{
    int h;

	h = 0;
	game->width = ft_strlen(map[h]);
	while (map[++h])
	{
		if (game->width != ft_strlen(map[h]))
			return (0);
	}
	game->height = h;
	return (1);
}

int check_walls(t_game *game, char **map)
{
	int i = 0;
	
	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			if (i == 0 && map[i][j] != '1')
				return (0);
			else if (map[i + 1] == NULL &&  map[i][j] != '1')
				return (0);
			else if (map[i][0] != '1')
				return (0);
			else if (map[i][j + 1] == '\0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int check_chars(t_game *game, char **map)
{
	int i;
	int j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				game->e.count++;
			else if (map[i][j] == 'P')
				game->p.count++;
			else if (map[i][j] == 'C')
				game->cc++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		if (game->e.count > 1 || game->p.count > 1)
			return (0);
		i++;
	}
	if (game->e.count < 1 || game->p.count < 1 || game->cc < 1)
		return (0);
	else if (game->e.count > 1 || game->p.count > 1)
		return (0);
	return (1);
}


int check_matrix(t_game *game, char **map)
{
    if(!is_rect(game, map))
        return (4);
	else if (!check_walls(game, map))
		return (5);
	else if (!check_chars(game, map))
		return (6);
	else if (!check_path(game, map))
		return (7);
	return (0);
}

// 4: "ERROR: wrong map format, must be a rectangle with the fewest nr of line breaks possible\n"
// 5: "ERROR: map should be surrounded by '1' chars\n"
// 6: "ERROR: map sould only contain one 'P' and 'E', at least one 'C' and '0' and '1'\n"
// eliminado: "ERROR: failed to copy matrix\n"
// 7: "ERROR: map has no valid path\n"
