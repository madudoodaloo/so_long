/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 04:13:35 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/04 17:26:08 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_img(t_img *img)
{
	img->height = 0;
	img->width = 0;
	img->img = NULL;
}

static void	init_pos(t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
}

static void	init_obj(t_obj *obj)
{
	init_pos(&obj->pos);
	init_img(&obj->img);
	obj->count = 0;
}

static void	init_game(t_game *game)
{
	game->fd = -1;
	game->init = 0;
	game->moves = 0;
	game->width = 0;
	game->height = 0;
	game->map = NULL;
	game->temp = NULL;
	init_obj(&game->c);
	init_obj(&game->e);
	init_obj(&game->p);
	init_obj(&game->wall);
	init_obj(&game->floor);
	init_obj(&game->e_eog);
}

void	init_var(t_prog *prog)
{
	prog->h = 64;
	prog->w = 64;
	prog->mlx = NULL;
	prog->win = NULL;
	init_game(&prog->game);
}