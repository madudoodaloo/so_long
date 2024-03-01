/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 04:13:35 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/01 08:42:24 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void init_img(t_img *img)
{
    img->height=0;
    img->width=0;
    img->img=NULL;
}

static void init_obj(t_obj *obj) 
{
    init_img(&obj->img);
    obj->x=0;
    obj->y=0;
    obj->count=0;
}

static void init_game(t_game *game)
{
    game->fd = -1;
    game->cc = 0;
    game->width = 0;
    game->height = 0;
    game->map = NULL;
    game->temp = NULL;
    //init_obj(game->c); /* seg fault alert */
    init_obj(&game->e);
    init_obj(&game->p);
    init_obj(&game->wall);
    init_obj(&game->floor);
    init_obj(&game->p_eog);
    init_obj(&game->e_eog);
    init_obj(&game->c);

}

void init(t_prog *prog)
{
    prog->h = 0;
    prog->w = 0;
    prog->mlx = NULL;
    prog->win = NULL;
    init_game(&prog->game);
}