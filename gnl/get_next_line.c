/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:16:35 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/01 06:01:13 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || fd < 0)
	{
		while (buff[i])
			buff[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (buff[0] || read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buff);
		if (ft_clean(buff))
			break ;
	}
	return (line);
}

/* #include <errno.h>
 int main()
{
	int fd = 0;
	char *line;
	
	if (BUFFER_SIZE < 0)
		return (printf("invalid buffer size\n"));
	fd = open("./tester.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("invalid fd: %d, errno: %d\n", fd, errno);
		perror("problem");
		exit (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s$", line);
		free(line);
	}
	close(fd);
}
 */