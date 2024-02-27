/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:43:55 by msilva-c          #+#    #+#             */
/*   Updated: 2024/02/27 19:06:15 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./gnl/get_next_line.h"
#include <stdio.h>
#include <unistd.h>


int is_ber(char *av)
{
    char    *format;
    int     i;
    int     j;

    if (av)
    {
        i = ft_strlen(av) - 4;
        format = ".ber";
        j = 0;
        while (av[i + j] == format[j])
        {
            j++;
            if(!av[i + j] && !format[j])
                return (1);
        }
    }
    return (0);
}

int valid_args(int ac, char *file)
{
    int map_fd;

    if (ac < 2)
        return(ft_printerror("ERROR: Insert map to launch, try:\n./so_long map.ber\n"));
    else if (ac > 2)
        return(ft_printerror("ERROR: Too many arguments, try:\n./so_long map.ber\n"));
    else if (!is_ber(file))
        return(ft_printerror("ERROR: Insert map in .ber format\n"));
    map_fd = open(file, O_RDONLY);
    if (map_fd == -1)
        return(ft_printerror("ERROR: .ber has invalid permissions (man chmod)\n"));
    return (map_fd);
}

char **get_matrix(int fd, int counter, char **map)
{
    char    *line;

    line = get_next_line(fd);
    if (line)
        map = get_matrix(fd, counter + 1, map);
    if (!map)
        map = malloc(sizeof(char *) * (counter + 1));
    map[counter] = line;
    return (map);
}

int	ft_error(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);

	return (0);
}

char **map_trim(char **map)
{
	char	*line = NULL;
	int i = 0;

	while(map[i])
		{
			line = ft_strtrim(map[i], WHITESPACES);
			printf("%s\n", line);
			free(map[i]);
			map[i] = line;
			i++;
		}
	map[i] = NULL;
	return (map);
}

static void	flood_fill(char **temp, char **map, int x, int y)
{
	if (check_pos(temp, map, x + 1, y))
		flood_fill(temp, map, x + 1, y);
	if (check_pos(temp, map, x - 1, y))
		flood_fill(temp, map, x - 1, y);
	if (check_pos(temp, map, x, y + 1))
		flood_fill(temp, map, x, y + 1);
	if (check_pos(temp, map, x, y - 1))
		flood_fill(temp, map, x, y - 1);
}

int check_map(char **map)
{
	char **temp;

	temp = map;
	
}

int check_objs(char **map)
{
	int c = 0;
	int e = 0;
	int p = 0;

	int i = 0;
	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				e++;
			else if (map[i][j] == 'P')
				p++;
			else if (map[i][j] == 'C')
				c++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				return (ft_printerror("Invalid chars on map\n"));
			j++;
		}
		if (e > 1 || p > 1)
			return (ft_printerror("Only 1 exit and 1 player are allowed\n"));
		i++;
	}
	if (e < 1 || p < 1 || c < 1)
		return (ft_printerror("Missing chars: 1 exit, 1 player and at least 1 collectible\n"));
	else if (e > 1 || p > 1)
		return (ft_printerror("Only 1 exit and 1 player are allowed\n"));
	return (check_path(map));
}

int check_walls(char **map)
{
	int i = 0;
	
	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			if (i == 0 && map[i][j] != '1')
				return (ft_printerror("Invalid walls\n"));
			else if (map[i + 1] == NULL &&  map[i][j] != '1')
				return (ft_printerror("Invalid walls\n"));
			else if (map[i][0] != '1')
				return (ft_printerror("Invalid walls\n"));
			else if (map[i][j + 1] == '\0' && map[i][j] != '1')
				return (ft_printerror("Invalid walls\n"));
			j++;
		}
		i++;
	}
	return (check_objs(map));
}

int	check_square(char **map)
{
	int i = 0;
	int width = 0;

	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			j++;
			if (i == 0)
				width = j;
		}
		if (j != width)
			return (ft_printerror("The map is not a rectangle\n"));
		i++;
	}
	return (check_walls(map));
}
