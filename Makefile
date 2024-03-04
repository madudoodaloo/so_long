NAME = so_long

SRCS = gnl/get_next_line_utils.c \
gnl/get_next_line.c \
paths.c args.c free.c imgs.c \
init.c libft.c matrix.c moves.c \
trim.c print.c ft_calloc.c main.c


OBJS = ${SRCS:.c=.o}
CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

all: $(NAME)

%.o: %.c
	$(CC) -g $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) mlx_linux/libmlx_Linux.a -lmlx_Linux -Lmlx_linux/ -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
			
clean:
	$(RM)	$(OBJS)

fclean: clean
	@rm -rf ${NAME}
 
re:	fclean	$(NAME)