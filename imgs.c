/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:22:40 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/04 17:45:02 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_prog *prog, void *img, int x, int y)
{
	mlx_put_image_to_window(prog->mlx, prog->win, img, x * 64, y * 64);
}

void	load_imgs(t_prog *prog, t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				put_img(prog, game->wall.img.img, j, i);
			else if (game->map[i][j] == '0')
				put_img(prog, game->floor.img.img, j, i);
			else if (game->map[i][j] == 'P')
				put_img(prog, game->p.img.img, j, i);
			else if (game->map[i][j] == 'E' && game->c.count)
				put_img(prog, game->e.img.img, j, i);
			else if (game->map[i][j] == 'E' && !game->c.count)
				put_img(prog, game->e_eog.img.img, j, i);
			else if (game->map[i][j] == 'C')
				put_img(prog, game->c.img.img, j, i);
			j++;
		}
		i++;
	}
}

void	*new_img(char *path, t_prog *prog)
{
	void	*img;

	img = mlx_xpm_file_to_image(prog->mlx, path, &prog->w, &prog->h);
	if (!img)
		print_error(8, prog);
	return (img);
}

void	get_imgs(t_game *game, t_prog *prog)
{
	game->c.img.img = new_img("./textures/collect.xpm", prog);
	game->e.img.img = new_img("./textures/exit_false.xpm", prog);
	game->p.img.img = new_img("./textures/player_left.xpm", prog);
	game->wall.img.img = new_img("./textures/wall.xpm", prog);
	game->floor.img.img = new_img("./textures/floor.xpm", prog);
	game->e_eog.img.img = new_img("./textures/exit_true.xpm", prog);
}
