/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:04:09 by msilva-c          #+#    #+#             */
/*   Updated: 2024/02/27 16:46:16 by msilva-c         ###   ########.fr       */
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

char	*ft_strtrim(char const *s1, char const *set)
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
	n = ft_strlen(s1);
	while (ft_setchecker(set, s1[n - 1]) && i < n)
		n--;
	str = (char *)malloc(sizeof(char) * (n - i + 1));
	if (!str)
		return (NULL);
	f = 0;
	while (s1[i] && i < n)
		str[f++] = s1[i++];
	str[f] = '\0';
	return (str);
}