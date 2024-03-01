/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:16:04 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/01 06:29:22 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlens(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buff)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = malloc(ft_strlens(line) + ft_strlens(buff) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (line && line[i])
	{
		new[i] = line[i];
		i++;
	}
	if (line)
		free(line);
	while (buff[j])
	{
		new[i++] = buff[j++];
		if (buff[j] == '\n')
			break ;
	}
	new[i] = '\0';
	return (new);
}

int	ft_clean(char *buff)
{
	int		i;
	int		j;
	int		flag;

	flag = 0;
	i = 0;
	j = 0;
	while (buff[i])
	{
		if (flag == 1)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			flag = 1;
		buff[i++] = '\0';
	}
	return (flag);
}
