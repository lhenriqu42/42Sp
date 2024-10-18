/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:28:40 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/10/18 08:50:07 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str;
    size_t i;
    size_t s_len;

    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup(""));
    if ((s_len - start) < len)
        len = s_len - start;
    str = (char *)malloc((len + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

void start(char **rest)
{
    if (!*rest)
        *rest = ft_strdup("");
}

int verify(char **buffer, char **rest, char **line, ssize_t bytes_read)
{
    if (buffer && *buffer)
        free(*buffer);
    if (bytes_read == 0 && *rest && **rest != '\0') // Se o resto tem algo
    {
        *line = ft_strdup(*rest);
        free(*rest);
        *rest = NULL;
        return (1); // Retorna a última linha do arquivo
    }
    if (bytes_read == 0 && (!rest || **rest == '\0')) // Fim do arquivo e nada no resto
    {
        free(*rest);
        *rest = NULL;
        return (0); // Retorna NULL para indicar fim do arquivo
    }
    if (bytes_read == -1)
        free(*line);

    return (0);
}

int read_fd(char **line, char *buffer, char **rest, int fd)
{
    ssize_t bytes_read;
    int new_line_index;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        *rest = ft_strjoin(*rest, buffer);
        new_line_index = get_new_line_index(*rest);
        if (new_line_index >= 0)
        {
            *line = ft_substr(*rest, 0, new_line_index + 1);
            if (!line)
                return (0);
            char *tmp = *rest;
            *rest = ft_strdup(*rest + new_line_index + 1);
            free(tmp);
            if (!rest)
                return (0);
            free(buffer);
            return (1);
        }
    }
    return (verify(&buffer, rest, line, bytes_read));
}

char *get_next_line(int fd)
{
    static char *rest = NULL;
    char *buffer;
    char *line;

    start(&rest);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);

    if (read_fd(&line, buffer, &rest, fd))
        return (line);
    else
        return (NULL);
}

