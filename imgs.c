/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:22:40 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/01 08:46:21 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	put_img(t_prog *prog, void *img, int x, int y)
{
	mlx_put_image_to_window(prog->mlx, prog->win, img, x * 64, y * 64);
}

void	draw_imgs(t_prog *prog, t_game *game)
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
			if (game->map[i][j] == '0')
				put_img(prog, game->floor.img.img, j, i);
			if (game->map[i][j] == 'P' && game->cc)
				put_img(prog, game->p.img.img, j, i);
			if (game->map[i][j] == 'P' && !game->cc)
				put_img(prog, game->p_eog.img.img, j, i);
            if (game->map[i][j] == 'E' && game->cc)
				put_img(prog, game->e.img.img, j, i);
			if (game->map[i][j] == 'E' && !game->cc)
				put_img(prog, game->e_eog.img.img, j, i);
			if (game->map[i][j] == 'C')
				put_img(prog,game->c.img.img, j, i);
			j++;
		}
		i++;
	}
}

void	*new_file_img(char *path, t_prog *prog)
{
	void	*img;

	img = mlx_xpm_file_to_image(prog->mlx, path, &prog->w, &prog->h);
	if (!img)
		return NULL;//error(path, &prog);
	return (img);
}

void	get_imgs(t_game *game, t_prog *prog)
{
	game->c.img.img = new_file_img("./assets/collect.xpm", prog);
	game->e.img.img = new_file_img("./assets/e.xpm", prog);
	game->p.img.img = new_file_img("./assets/p.xpm", prog);
	game->wall.img.img = new_file_img("./assets/wall.xpm", prog);
	game->floor.img.img = new_file_img("./assets/floor.xpm", prog);
	game->p_eog.img.img = new_file_img("./assets/p_eog.xpm", prog);
    game->e_eog.img.img = new_file_img("./assets/e_eog.xpm", prog);
}