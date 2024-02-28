/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:51:35 by msilva-c          #+#    #+#             */
/*   Updated: 2024/02/27 22:32:41 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_matrix(char **map)
{
	int i;

	i = 0;
    if (map)
    {
        while (map[i])
			free(map[i++]);
		free(map);
    }
}

void    end_game(t_game *game)
{
    if (game.fd != -1)
        close(game->fd);
    free_matrix(game->matrix);
}
