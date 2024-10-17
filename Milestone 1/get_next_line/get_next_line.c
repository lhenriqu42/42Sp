/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:28:40 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/10/17 11:06:24 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void *free_alloc(char **line, char **rest)
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
    return (NULL);
}

static char *store_rest(char **line, int nl_position)
{
    char *str;
    int i;
    int len;

    i = nl_position;
    while ((*line)[i])
        i++;
    len = i - nl_position;
    str = malloc(len + 1);
    if (!str)
        return (NULL);
    str[len] = '\0';
    ft_strlcpy(str, *line + nl_position, len + 1);
    return str;
}

static char *get_left_part(char **line, int nl_position)
{
    char *str = malloc(nl_position + 2);
    if (!str)
        return (NULL);
    ft_strlcpy(str, *line, nl_position + 2);
    str[nl_position + 1] = '\0';
    return (str);
}

static char *return_line(char **line, char **rest, int nl_position, int n)
{
    char *left_part;
    char *new_rest;

    if (nl_position == -1)
    {
        free_alloc(NULL, rest);
        return *line;
    }
    else
    {
        left_part = get_left_part(line, nl_position);
        if (!left_part)
            return (NULL);
        new_rest = ft_strdup(*line + nl_position + 1);
        if (!new_rest)
        {
            free(left_part);
            return (NULL);
        }
        free(*rest);
        *rest = new_rest;
        return *line;
    }
}

char *get_next_line(int fd)
{
    static char *rest;
    char buffer[BUFFER_SIZE + 1];
    char *line;
    int chars_read;

    if (!rest)
        rest = ft_strdup("");
    line = ft_strdup(rest);
    chars_read = BUFFER_SIZE;

    while (chars_read == BUFFER_SIZE && get_new_line_index(line) == -1)
    {
        chars_read = read(fd, buffer, BUFFER_SIZE);
        if (chars_read < 0)
            return (free_alloc(&line, &rest));
        buffer[chars_read] = '\0';
        line = ft_strjoin(line, buffer);
    }
    return (return_line(&line, &rest, get_new_line_index(line), chars_read));
}
