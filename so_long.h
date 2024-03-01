/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:42:32 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/01 08:46:55 by msilva-c         ###   ########.fr       */
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

typedef struct img_s
{
	int		width;
	int		height;
	void	*img;
}			t_img;

typedef struct s_obj
{
	int x;
	int y;
	int count;
	t_img img;
}	t_obj;

typedef struct s_game
{
	int		fd;
	int		cc; /* collectibles count */
	t_obj	c;
	t_obj 	e;
	t_obj	p;
	t_obj 	wall;
	t_obj 	floor;
	t_obj	p_eog; /* duck with flower */
	t_obj	e_eog; /* pata happy */
	int 	width; /* x */
	int 	height; /* y */
	char	**map;
	char	**temp;
}	t_game;

typedef struct s_prog
{
	void	*mlx;
	void	*win;
	t_game 	game;
	int	w;
	int h;
}			t_prog;



/* init */
void init(t_prog *prog);
void end_prog(t_prog *prog);


/* args.c */
int check_args(int ac, char *file);
int is_ber(char *file);

/* matrix.c */
char **get_matrix(int fd, int counter, char **map);
int is_rect(t_game *game, char **map);
int check_walls(t_game *game, char **map);
int check_chars(t_game *game, char **map);
int check_matrix(t_game *game, char **map);

/* paths.c */
char **cpy_matrix(char **src, int height);
void	get_coord(t_game *game, t_obj *token, char c);
int	check_pos(char **temp, t_game *game, int x, int y);
void	flood_fill(char **temp, t_game *game, int x, int y);
int check_path(t_game *game, char **map);

/* str_utils.c */
int ft_strlen(char *str);
char *ft_strdup(char *str);
int	str_srch(char *str, char c);
void    free_matrix(char **map);
void printhere(char **str);

/* imgs */
void	put_img(t_prog *prog, void *img, int x, int y);
void	draw_imgs(t_prog *prog, t_game *game);
void	*new_file_img(char *path, t_prog *prog);
void	get_imgs(t_game *game, t_prog *prog);



#endif