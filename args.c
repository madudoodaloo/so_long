/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:52:48 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/04 17:21:30 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_ber(char *file)
{
	char	*format;
	int		i;
	int		j;

	if (file)
	{
		i = (ft_strlen(file) - 4);
		format = ".ber";
		j = 0;
		while (file[i + j] == format[j])
		{
			j++;
			if (!file[i + j] && !format[j])
				return (1);
		}
	}
	return (0);
}

int	check_args(t_prog *prog, int ac, char *file)
{
	if (ac < 2)
		return (print_error(1, prog));
	else if (ac > 2)
		return (print_error(1, prog));
	else if (!is_ber(file))
		return (print_error(2, prog));
	return (0);
}
