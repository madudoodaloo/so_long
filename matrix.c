/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:09:50 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/04 22:05:34 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **get_matrix(int fd, int counter, char **map)
{
	char *line;

	line = get_next_line(fd);
	if (line)
		map = get_matrix(fd, counter + 1, map);
	if (!map)
		map = ft_calloc(sizeof(char *), (counter + 1));
	map[counter] = line;
	return (map);
}

/* nao esquecer alterar o h e o w depois de tar trim do mapa final */
// attention: the width and height values do not match indexes.
// to get the maximum index, subtract 1
static int is_rect(t_game *game, char **map)
{
	int h;

	h = 0;
	game->width = ft_strlen(map[h]);
	if (game->width == 0)
		return (0);
	while (map[++h])
	{
		if (game->width != ft_strlen(map[h]))
			return (0);
	}
	game->height = h;
	return (1);
}

static int check_walls(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 && map[i][j] != '1')
				return (0);
			else if (map[i + 1] == NULL && map[i][j] != '1')
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

static int check_chars(t_game *game, char **map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				game->e.count++;
			else if (map[i][j] == 'P')
				game->p.count++;
			else if (map[i][j] == 'C')
				game->c.count++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
	}
	if (game->e.count < 1 || game->p.count < 1 || game->c.count < 1)
		return (0);
	else if (game->e.count > 1 || game->p.count > 1)
		return (0);
	return (1);
}

void update_size(t_game *game)
{
	int h;
	
	h = 0;
	game->width = ft_strlen(game->map[0]);
	while (game->map[h])
			h++;
	game->height = h;
}

int check_matrix(t_prog *prog, t_game *game, char **map)
{
	if (!is_rect(game, map))
		return (print_error(4, prog));
	prog->game.map = trim_nl(map);
	update_size(game);
	if (!check_walls(prog->game.map))
		return (print_error(5, prog));
	else if (!check_chars(game, prog->game.map))
		return (print_error(6, prog));
	else if (!check_path(game, prog->game.map))
		return (print_error(7, prog));
	return (1);
}
