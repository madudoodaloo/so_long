#include "so_long.h"

void init_img(t_img *img){
    img->height=0;
    img->width=0;
    img->img=NULL;
}

void init_obj(t_obj *obj) {
    init_img(&obj->img);
    obj->x =0;
    obj->y=0;
}

void init_player(t_player *player) {
    init_obj(player);
}

void init_map(t_map *map) {
    map->c=NULL;
    map->e=NULL;
    map->floor=NULL;
    map->wall=NULL;
    map->height=NULL;
    init_player(&map->player);
}

// adicionar coisas aqui sempre que adiciones nas structs
void init(t_game *mlx) {
    mlx->mlx=NULL;
    mlx->mlx_win=NULL;
    init_map(&mlx->map);
}