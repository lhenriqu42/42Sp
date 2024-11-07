/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:28:40 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/11/07 11:10:54 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t custom_read(t_data **data)
{
    ssize_t bytes_read;
    int i;

    i = -1;
    bytes_read = read((*data)->fd, (*data)->buffer, BUFFER_SIZE);
    while (i < bytes_read && (*data)->buffer[i] != '\n')
        i++;
    if (i < bytes_read && (*data)->buffer[i] == '\n')
        (*data)->nl_index = i;
    else
        (*data)->nl_index = -1;
    return (bytes_read);
}

void fill_string_with_buffer(t_data **data, ssize_t bytes_read)
{
    int i;

    i = -1;
    if ((*data)->nl_index == -1)
    {
        while (++i < bytes_read)
            (*data)->string[(*data)->str_len++] = (*data)->buffer[i];
    }
    else
    {

    }
}

static char *read_line(t_data **data)
{
    ssize_t bytes_read;

    clean_string(data);
    while ((*data)->nl_index == -1)
    {
        bytes_read = custom_read(data);
        if (bytes_read == -1)
            return (NULL);
        if (bytes_read == 0)
            break;
        fill_string_with_buffer(data, bytes_read);
    }
    return (malloc_string((*data)->string))
}

char *get_next_line(int fd)
{
    static t_data *data;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    if (init_data(&data, fd) == NULL)
        return (NULL);
    return (read_line(&data));
}
