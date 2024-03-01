/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-c <msilva-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:52:48 by msilva-c          #+#    #+#             */
/*   Updated: 2024/03/01 05:10:46 by msilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_ber(char *file)
{
    char    *format;
    int     i;
    int     j;

    if (file)
    {
        i = (ft_strlen(file) - 4);
        format = ".ber";
        j = 0;
        while (file[i + j] == format[j])
        {
            j++;
            if(!file[i + j] && !format[j])
                return (1);
        }
    }
    return (0);
}

int check_args(int ac, char *file)
{
    if (ac < 2)
        return(1);
    else if (ac > 2)
        return(1);
    else if (!is_ber(file))
        return(2);
    return (0);
}

// 10: "ERROR: Insert one map to launch, try:\n./so_long map.ber\n"
// 2: "ERROR: Insert map in .ber format\n"