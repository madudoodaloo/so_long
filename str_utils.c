/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:45:14 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/01 06:07:53 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        ;
    return(i);
}

char *ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*out;

	i = 0;
	len = ft_strlen((char *)str);
	out = (char *)malloc(len * sizeof(char) + 1);
	if (!out)
		return (NULL);
	out[len] = '\0';
	while (str[i] != '\0')
	{
		out[i] = str[i];
		i++;
	}
	return (out);
}

int	str_srch(char *str, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}

void    free_matrix(char **map)
{
	int i;

	i = 0;
    if (map)
    {
        while (map[i])
			free(map[i++]);
		free(map);
    }
}


