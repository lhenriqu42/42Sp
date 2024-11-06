/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:28:40 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/11/06 16:28:51 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void read_process(t_data **data)
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

void read_line(t_data **data)
{
    read_process(data);
}

char *get_next_line(int fd)
{
    static t_data *data;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    if (init_data(&data, fd) == NULL)
        return (NULL);
    read_line(&data);
}
