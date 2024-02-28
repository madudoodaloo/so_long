/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:12:14 by msilva-c          #+#    #+#             */
/*   Updated: 2024/02/28 00:33:23 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	key_handler(int keycode, t_game *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		mlx_loop_end(mlx->mlx);
	}
	else if (keycode == UP)
	{
		mlx->bean.y -= SQSIZE;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->bean.img.img,
			mlx->bean.x, mlx->bean.y);
	}
	else if (keycode == DOWN)
	{
		mlx->bean.y += SQSIZE;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->bean.img.img,
			mlx->bean.x, mlx->bean.y);
	}
	else if (keycode == LEFT)
	{
		mlx->bean.x -= SQSIZE;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->bean.img.img,
			mlx->bean.x, mlx->bean.y);
	}
	else if (keycode == RIGHT)
	{
		mlx->bean.x += SQSIZE;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->bean.img.img,
			mlx->bean.x, mlx->bean.y);
	}
	printf("%i\n", keycode);
} */

int	start_game(t_game *game)
{
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window(mlx.mlx, 400, 200, "Duck it out!");
		game mlx_xpm_file_to_image(mlx.mlx, "./assets/1.xpm",
				&mlx.bean.img.width, &mlx.bean.img.height);
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.bean.img.img, 0, 0);
		mlx_key_hook(mlx.mlx_win, &key_handler, &mlx);
		mlx_loop(mlx.mlx);
	
}

int	main(int ac, char **av)
{
	t_game game;

	init(&game);
	if (!valid_args(ac, av[1], &game.map) && game.map.fd != -1)
	{
		game->matrix = map_trim(get_matrix(fd, 0, NULL));
		if (game->matrix && !check_square(&game.map, game.map.matrix) && !check_path(&game))
			start_game(&game);
	}	
	end_game(&game);
}