/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:31:02 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/11/07 09:48:31 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_data *calloc_new_struct(int fd)
{
    t_data *new_data;
    int i;

    new_data = (t_data *)malloc(sizeof(t_data));
    if (!new_data)
        return (NULL);
    new_data->fd = fd;
    i = 0;
    while (i < BUFFER_SIZE)
        new_data->buffer[i++] = '\0';
    i = 0;
    while(i < ARRAY_LENTH)
        new_data->string[i++] = '\0';
    new_data->nl_index = -1;
    new_data->str_len = 0;
    new_data->next = NULL;
    return (new_data);
}

t_data *init_data(t_data **data, int fd)
{
    t_data *current;

    if (!*data)
        *data = create_data(fd);
    current = *data;
    while (current)
    {
        		if (current->fd == fd)
			return (current);
		if (!current->next)
		{
			current->next = create_data(fd);
			return (current->next);
		}
		current = current->next;
    }
    return (*data);
}
