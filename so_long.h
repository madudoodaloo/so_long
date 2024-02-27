/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:42:32 by msilva-c          #+#    #+#             */
/*   Updated: 2024/02/21 19:24:07 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx_linux/mlx.h"
#include <unistd.h>

#define ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define SQSIZE 64
#define WHITESPACES " \f\n\r\t\v"




/* obj = {
	img
	pos
}
player = {
	img
	pos
	keys
}
player = (t_player *)malloc(sizeof(t_player));
player.pos = pos
player.img = img;
player.keys = keys;

change_img(t_obj obj){
	obj.img = img2;
}

update() {
	change_img((t_obj)player)
} */

typedef struct img_s
{
	void	*img;
	int		width;
	int		height;
}			t_img;

// Obj é o pai
typedef struct s_obj
{
	int x;
	int y;
	t_img img;
}	t_obj;

// Player é o filho, todos os valores q forem
//  iguais em obj e player têm que estar na mesma ordem
typedef struct s_player
{
	int x;
	int y;
	t_img img;
}	t_player;

typedef struct s_map
{
	t_obj *c;
	t_obj *e;
	t_obj *wall;
	t_obj *floor;
	t_player player;
	int width; /* x */
	int height; /* y */
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_map 	map;
}			t_game;


int		ft_strlen(char *str);
int		ft_printerror(char *msg);
int		is_ber(char *av);
int	ft_error(char c);
char	*ft_strtrim(char const *s1, char const *set);
char	**get_matrix(int fd, int counter, char **map);
int		valid_args(int ac, char *map);
char 	**map_trim(char **map);

#endif