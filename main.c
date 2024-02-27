/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:12:14 by msilva-c          #+#    #+#             */
/*   Updated: 2024/02/27 18:37:01 by msilva-c         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_game game;

	char **new_map;
	init(&game);

	int fd = valid_args(ac, av[1]);
	if (fd != -1)
	{
		char **map = get_matrix(fd, 0, NULL);
		new_map = map_trim(map);
		if (!new_map)
			ft_free_matrix(map);
		//printf("%d\n", check_square(new_map));
		else if (!check_square(new_map))


		ft_free_matrix(new_map);
		mlx.mlx = mlx_init();
		mlx.mlx_win = mlx_new_window(mlx.mlx, 400, 200, "Duck it out!");
		mlx.bean.img.img = mlx_xpm_file_to_image(mlx.mlx, "./assets/1.xpm",
				&mlx.bean.img.width, &mlx.bean.img.height);
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.bean.img.img, 0, 0);
//		mlx_key_hook(mlx.mlx_win, &key_handler, &mlx);

		mlx_loop(mlx.mlx);
	}
	close(fd);
	return 0;
}