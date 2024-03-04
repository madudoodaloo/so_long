/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:00:39 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/04 22:05:55 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_setchecker(char const *set, char c)
{
	size_t	s;

	s = 0;
	while (set[s])
	{
		if (set[s] == c)
			return (1);
		s++;
	}
	return (0);
}

static char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	n;
	size_t	i;
	size_t	f;
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	while (ft_setchecker(set, s1[i]) && s1[i])
		i++;
	n = ft_strlen((char *)s1);
	while (ft_setchecker(set, s1[n - 1]) && i < n)
		n--;
	str = (char *)ft_calloc(sizeof(char), (n - i + 1));
	if (!str)
		return (NULL);
	f = 0;
	while (s1[i] && i < n)
		str[f++] = s1[i++];
	str[f] = '\0';
	return (str);
}

static int size_dp(char **map)
{
    int i;
    i = 0;

    while(map[i])
        i++;
    return (i);
}

char **trim_nl(char **map)
{
    char **temp;
    int size;
    size = size_dp(map);
    temp = ft_calloc(sizeof(char *), size + 1);
    int i;
    i = 0;
    while (size)
    {
        temp[i] = ft_strtrim(map[i],"\n");
        size--;
        i++;
    }
    free_matrix(map);
    return(temp);
}