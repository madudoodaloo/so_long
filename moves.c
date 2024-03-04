/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:44:44 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/04 17:28:24 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	moves_ad(int x, t_prog *prog, t_game *game)
{
	if (game->map[game->p.pos.y][game->p.pos.x + x] == 'C')
	{
		game->c.count--;
		game->map[game->p.pos.y][game->p.pos.x] = '0';
		game->p.pos.x += x;
		game->map[game->p.pos.y][game->p.pos.x] = 'P';
	}
	else if (game->map[game->p.pos.y][game->p.pos.x + x] == '0')
	{
		game->map[game->p.pos.y][game->p.pos.x] = '0';
		game->p.pos.x += x;
		game->map[game->p.pos.y][game->p.pos.x] = 'P';
	}
	game->moves++;
	counter(prog);
}

static void	moves_ws(int y, t_prog *prog, t_game *game)
{
	if (game->map[game->p.pos.y + y][game->p.pos.x] == 'C')
	{
		game->c.count--;
		game->map[game->p.pos.y][game->p.pos.x] = '0';
		game->p.pos.y += y;
		game->map[game->p.pos.y][game->p.pos.x] = 'P';
	}
	else if (game->map[game->p.pos.y + y][game->p.pos.x] == '0')
	{
		game->map[game->p.pos.y][game->p.pos.x] = '0';
		game->p.pos.y += y;
		game->map[game->p.pos.y][game->p.pos.x] = 'P';
	}
	game->moves++;
	counter(prog);
}

void	move_y(int y, t_prog *prog, t_game *game)
{
	t_pos	p_pos;

	p_pos = game->p.pos;
	if (game->map[p_pos.y + y][p_pos.x] != '1' \
		&& game->map[p_pos.y + y][p_pos.x] != 'E')
		moves_ws(y, prog, game);
	else if (game->map[p_pos.y + y][p_pos.x] == 'E')
		check_game_over(prog);
	mlx_clear_window(prog->mlx, prog->win);
	load_imgs(prog, game);
}

void	move_x(int x, t_prog *prog, t_game *game)
{
	t_pos	p_pos;

	p_pos = game->p.pos;
	if (game->p.img.img)
		mlx_destroy_image(prog->mlx, game->p.img.img);
	if (x > 0 && game->c.count)
		game->p.img.img = new_img("./assets/player_right.xpm", prog);
	else if (x > 0 && !game->c.count)
		game->p.img.img = new_img("./assets/player_right_exit.xpm", prog);
	else if (game->c.count)
		game->p.img.img = new_img("./assets/player_left.xpm", prog);
	else
		game->p.img.img = new_img("./assets/player_left_flower.xpm", prog);
	if (game->map[p_pos.y][p_pos.x + x] != '1' \
			&& game->map[p_pos.y][p_pos.x + x] != 'E')
		moves_ad(x, prog, game);
	else if (game->map[p_pos.y][p_pos.x + x] == 'E')
		check_game_over(prog);
	mlx_clear_window(prog->mlx, prog->win);
	load_imgs(prog, game);
}

int	key_handler(int key, t_prog *prog)
{
	if (key == ESC)
		exit_and_free(prog);
	else if (key == A_KEY)
		move_x(-1, prog, &prog->game);
	else if (key == D_KEY)
		move_x(1, prog, &prog->game);
	else if (key == W_KEY)
		move_y(-1, prog, &prog->game);
	else if (key == S_KEY)
		move_y(1, prog, &prog->game);
	return (0);
}
