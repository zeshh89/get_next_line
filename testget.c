/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testget.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-an2 <jose-an2@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:40:22 by jose-an2          #+#    #+#             */
/*   Updated: 2025/11/02 18:52:51 by jose-an2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int   fd;
    char *line;
    int   i = 1;

    if (argc != 2)
    {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Línea %d: %s", i, line);
        free(line);
        i++;
    }
    close(fd);
    return (0);
}
