#include "so_long.h"

void init_img(t_img *img)
{
    img->height=0;
    img->width=0;
    img->img=NULL;
}

void init_obj(t_obj *obj) 
{
    init_img(&obj->img);
    obj->x=0;
    obj->y=0;
}

void init_player(t_player *player) 
{
    init_obj(&player->p);
    init_img(&player->p_end);
}

void init_map(t_map *map) 
{
    map->c=NULL;
    map->e=NULL;
    map->wall=NULL;
    map->floor=NULL;
    map->width = 0;
    map->height = 0;
    map->fd = -1;
    map->matrix = NULL;
    map->temp = NULL;
    init_player(&map->player);
}

void init(t_game *game)
{
    game->mlx = NULL;
    game->mlx_win = NULL;
    init_map(&game->map);
}