/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:44:18 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/01 08:48:33 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	game_init(t_prog *prog)
{
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, prog->game.width * 64, prog->game.height * 64, "SO_LONG");
	//game.img = malloc(sizeof(t_img));
	// game.moves = 0;
	// game.map.over = 0;
	get_imgs(&prog->game, prog);
	draw_imgs(prog,&prog->game);
	// mlx_key_hook(game.win, read_keys, &game);
	// mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop(prog->mlx);
}

int	main(int ac, char **av)
{
	t_prog prog;
	
	if (!check_args(ac, av[1]))
	{
		init(&prog);
		
		prog.game.fd = open(av[1], O_RDONLY);
		if (prog.game.fd != -1)
		{
			prog.game.map = get_matrix(prog.game.fd, 0, NULL);
			int i = check_matrix(&prog.game, prog.game.map);
			game_init(&prog);
		}
		else
			return (3);
		end_prog(&prog);
	}
	return (0);
}

// 3: "ERROR: failed to open the given map (man chmod)\n";