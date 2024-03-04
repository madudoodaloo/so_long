/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:34:45 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/04 17:29:12 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	counter(t_prog *prog)
{
	char	*nbr;

	nbr = ft_itoa(prog->game.moves);
	write(1, "moves count: ", 14);
	write(1, nbr, ft_strlen(nbr));
	write(1, "\n", 1);
	free(nbr);
}

int	print_error(int n, t_prog *prog)
{
	if (n == 1)
		write(1, "Error: Insert one map to launch\n", 32);
	else if (n == 2)
		write(1, "Error: Insert map in .ber format\n", 33);
	else if (n == 3)
		write(1, "Error: failed to open the given map\n", 36);
	else if (n == 4)
		write(1, "Error: wrong map format, must be rectangular\n", 45);
	else if (n == 5)
		write(1, "Error: bad map limits\n", 22);
	else if (n == 6)
		write(1, "Error: bad characters\n", 22);
	else if (n == 7)
		write(1, "Error: map has no valid path\n", 29);
	else if (n == 8)
		write(1, "invalid img path, check imgs.c/get_imgs\n", 40);
	exit_and_free(prog);
	return (1);
}
