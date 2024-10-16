/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:28:40 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/10/16 13:02:19 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	*free_alloc(char **line, char **rest, char **buffer)
{
    if (line && *line)
    {
        free(*line);
        *line = NULL;
    }
    if (rest && *rest)
    {
        free(*rest);
        *rest = NULL;
    }
    if (buffer && *buffer)
    {
        free(*buffer);
        *buffer = NULL;
    }
    return (NULL);
}


char *get_next_line(int fd)
{
    static char *rest;
    char *buffer;     
    char *line;       
    int chars_read;

    if (!rest)
        rest = ft_strdup("");                         
    line = ft_strdup(rest);                           
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (buffer == NULL)
        return (NULL);
    chars_read = BUFFER_SIZE;

    while (chars_read == BUFFER_SIZE && get_new_line_index(line) == -1)
    {
        chars_read = read(fd, buffer, BUFFER_SIZE);
        if (chars_read < 0)
            return (free_alloc(&line, &rest, &buffer));
        buffer[chars_read] = '\0';
        line = ft_strjoin(line, buffer);
    }
}