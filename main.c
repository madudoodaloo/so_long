/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:44:18 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/04 17:26:14 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_prog *prog)
{
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, prog->game.width * 64,
			prog->game.height * 64, "SO_LONG");
	get_imgs(&prog->game, prog);
	load_imgs(prog, &prog->game);
	mlx_key_hook(prog->win, key_handler, prog);
	mlx_hook(prog->win, 17, 0, exit_and_free, &prog->game);
	mlx_loop(prog->mlx);
}

int	main(int ac, char **av)
{
	t_prog prog;

	init_var(&prog);
	if (!check_args(&prog, ac, av[1]))
	{
		prog.game.fd = open(av[1], O_RDONLY);
		if (prog.game.fd != -1)
		{
			prog.game.map = get_matrix(prog.game.fd, 0, NULL);
			if (check_matrix(&prog, &prog.game, prog.game.map))
			{
				prog.game.init = 1;
				game_init(&prog);
			}
		}
		else
			return (print_error(3, &prog));
	}
	return (0);
}