/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 03:42:07 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/01 07:18:15 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **cpy_matrix(char **src, int height)
{
	int		i;
	char 	**cpy;

	i = -1;
	cpy = (char **)malloc(sizeof(char *) * (height + 1));
    if (!cpy)
        return (NULL);
	while (++i < height)
		cpy[i] = ft_strdup(src[i]);
	cpy[i] = NULL;
    if (i != height)
    {
		free_matrix(cpy);
		return (NULL);
	}
	return (cpy);
}


// returns coords in the right index obviously

void	get_coord(t_game *game, t_obj *token, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == c)
			{
				token->x = j;
				token->y = i;
			}
			j++;
		}
		i++;
	}
}

int	check_pos(char **temp, t_game *game, int x, int y)
{
	// printf("x %d, y %d", x, y);
	if (y < 0 || y >= game->height || x < 0 || x >= game->width)
		return (0);
	if (temp[y][x] == 'E')
		temp[y][x] = '1';
	if (temp[y][x] != '1' && temp[y][x] != 'X')
	{
		temp[y][x] = 'X';
		return (1);
	}
	return (0);
}

void	flood_fill(char **temp, t_game *game, int x, int y)
{
	// printhere(temp);
	// printf("\n$\n");
	if (check_pos(temp, game, x + 1, y))
		flood_fill(temp, game, x + 1, y);
	if (check_pos(temp, game, x - 1, y))
			flood_fill(temp, game, x - 1, y);
	if (check_pos(temp, game, x, y + 1))
		flood_fill(temp, game, x, y + 1);
	if (check_pos(temp, game, x, y - 1))
		flood_fill(temp, game, x, y - 1);
}

int check_path(t_game *game, char **map)
{
    char    **temp;
    
    game->temp = cpy_matrix(map, game->height);
    temp = game->temp;
	printhere(temp);
    if (!temp)
		return (0);
    get_coord(game, &game->p, 'P');
    flood_fill(temp, game, game->p.y, game->p.y);
    while(*temp != NULL)
    {
        if (str_srch(*temp, 'C') || str_srch(*temp, 'E'))
            return (0);
        temp++;
    }
    return (1);
}