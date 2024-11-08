/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:31:02 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/11/08 18:49:34 by lhenriqu         ###   ########.fr       */
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
	while (i < ARRAY_SIZE)
		new_data->string[i++] = '\0';
	new_data->nl_index = -1;
	new_data->str_len = 0;
	new_data->next = NULL;
	return (new_data);
}

t_data *init_data(t_data **data, int fd)
{
	t_data *current;
	int i;

	if (!*data)
		*data = calloc_new_struct(fd);
	current = *data;
	while (current)
	{
		if (current->fd == fd)
		{
			i = -1;
			while (++i < ARRAY_SIZE)
				current->string[i] = '\0';
			current->str_len = 0;
			return (current);
		}
		if (!current->next)
		{
			current->next = calloc_new_struct(fd);
			return (current->next);
		}
		current = current->next;
	}
	return (current);
}

char *malloc_string(t_data *data)
{
	char *str;
	int i;

	if (data->str_len == 0)
		return (NULL);
	i = -1;
	str = (char *)malloc(data->str_len + 1);
	while (++i <= data->str_len)
		str[i] = data->string[i];
	return (str);
}

ssize_t custom_read(t_data *data)
{
	ssize_t bytes_read;
	int i;

	i = -1;
	while (++i < BUFFER_SIZE)
		data->buffer[i] = '\0';
	bytes_read = read(data->fd, data->buffer, BUFFER_SIZE);
	i = 0;
	while (i < bytes_read && data->buffer[i] != '\n')
		i++;
	if (i < bytes_read && data->buffer[i] == '\n')
		data->nl_index = i;
	else
		data->nl_index = -1;
	return (bytes_read);
}