/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 04:26:06 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/01 04:58:56 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void init_img(t_img *img)
// {
//     img->height=0;
//     img->width=0;
//     img->img=NULL;
// }

// static void init_obj(t_obj *obj) 
// {
//     init_img(&obj->img);
//     obj->x=0;
//     obj->y=0;
// }

static void end_game(t_game *game)
{
    if(game->map)
        free_matrix(game->map);
    if(game->temp)
        free_matrix(game->temp);
    // if(&game->e.img.img);
    //     free(&game->e.img.img);
    // if(&game->p.img.img);
    //     free(&game->p.img.img);
    // if(&game->wall.img.img);
    //     free(&game->wall.img.img);
    // if(&game->floor.img.img);
    //     free(&game->floor.img.img);
    // if(&game->eog.img.img);
    //     free(&game->eog.img.img);
    // if(game->c.img.img);
    //     free(game->c.img.img);
}

void end_prog(t_prog *prog)
{
    //prog->mlx = NULL;
    //prog->mlx_win = NULL;
    end_game(&prog->game);
}