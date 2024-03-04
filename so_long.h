/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:42:32 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/04 22:03:39 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define ESC 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

typedef struct s_img
{
	int		width;
	int		height;
	void	*img;
}			t_img;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_obj
{
	t_pos	pos;
	t_img	img;
	int		count;
}			t_obj;

typedef struct s_game
{
	t_obj	c;
	t_obj	e;
	t_obj	p;
	t_obj	wall;
	t_obj	floor;
	t_obj	e_eog;
	int		fd;
	int		init;
	int		moves;
	int		width;
	int		height;
	char	**map;
	char	**temp;
}			t_game;

typedef struct s_prog
{
	void	*mlx;
	void	*win;
	t_game	game;
	int		w;
	int		h;
}			t_prog;

/* args.c */
int			check_args(t_prog *prog, int ac, char *file);

/* init.c */
void		init_var(t_prog *prog);

/* libft utils */
int			ft_strlen(char *str);
char		*ft_strdup(char *str);
int			str_srch(char *str, char c);
char		*ft_itoa(int a);

/* matrix.c */
char		**get_matrix(int fd, int counter, char **map);
int			check_matrix(t_prog *prog, t_game *game, char **map);

/* paths.c */
int			check_path(t_game *game, char **map);

/* free and exit*/
void		free_matrix(char **map);
int			exit_and_free(t_prog *prog);
void		check_game_over(t_prog *prog);

/* imgs */
void		put_img(t_prog *prog, void *img, int x, int y);
void		load_imgs(t_prog *prog, t_game *game);
void		*new_img(char *path, t_prog *prog);
void		get_imgs(t_game *game, t_prog *prog);

/* moves */
void		move_x(int x, t_prog *prog, t_game *game);
void		move_y(int y, t_prog *prog, t_game *game);
int			key_handler(int key, t_prog *prog);

/* print in terminal */
void		counter(t_prog *prog);
int			print_error(int n, t_prog *prog);

/* trim */
char **trim_nl(char **map);
void update_size(t_game *game);
void	*ft_calloc(size_t nmemb, size_t n);



/* debug.c */
// void printhere(char **str);
#endif