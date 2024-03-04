/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:45:14 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/04 22:45:25 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
			free(map[i++]);
		free(map);
	}
}

int	exit_and_free(t_prog *prog)
{
	if (prog->game.init)
	{
		mlx_destroy_image(prog->mlx, prog->game.c.img.img);
		mlx_destroy_image(prog->mlx, prog->game.e.img.img);
		mlx_destroy_image(prog->mlx, prog->game.e_eog.img.img);
		mlx_destroy_image(prog->mlx, prog->game.floor.img.img);
		mlx_destroy_image(prog->mlx, prog->game.p.img.img);
		mlx_destroy_image(prog->mlx, prog->game.wall.img.img);
		mlx_destroy_window(prog->mlx, prog->win);
		mlx_destroy_display(prog->mlx);
		free(prog->mlx);
	}
	free_matrix(prog->game.map);
	free_matrix(prog->game.temp);
	exit(0);
}

void	check_game_over(t_prog *prog)
{
	if (!prog->game.c.count)
		exit_and_free(prog);
}
