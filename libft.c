/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:39:50 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/04 17:05:36 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		;
	return (i);
}

char	*ft_strdup(char *str)
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

static size_t	ft_nbrcount(int a)
{
	size_t	len;

	len = 0;
	if (a == 0)
		len++;
	if (a < 0)
	{
		a *= -1;
		len++;
	}
	while (a)
	{
		a /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int a)
{
	char		*str;
	size_t		len;
	long int	nb;

	nb = a;
	len = ft_nbrcount(nb);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (a == 0)
		str[0] = 48;
	str[len--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[len--] = 48 + nb % 10;
		nb /= 10;
	}
	return (str);
}
