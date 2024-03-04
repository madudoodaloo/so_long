/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:01:32 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/04 22:03:28 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n--)
	{
		*str = c;
		str++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t n)
{
	void	*ptr;

	ptr = malloc(nmemb * n);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', nmemb * n);
	return (ptr);
}
