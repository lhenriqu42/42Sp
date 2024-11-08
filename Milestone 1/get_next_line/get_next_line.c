/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:28:40 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/11/08 18:53:01 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void clean_buffer(t_data *data)
{
	int i;
	int j;
	char temp[BUFFER_SIZE];

	i = 0;
	j = data->nl_index + 1;
	while (j < BUFFER_SIZE)
	{
		temp[i] = data->buffer[j];
		i++;
		j++;
	}
	while (i < BUFFER_SIZE)
		temp[i++] = '\0';
	i = -1;
	while (++i < BUFFER_SIZE)
		data->buffer[i] = temp[i];
}

void fill_string_with_buffer(t_data *data, ssize_t bytes_read)
{
	int i;

	i = -1;
	if (data->nl_index == -1)
	{
		while (++i < bytes_read)
			data->string[data->str_len++] = data->buffer[i];
	}
	else
	{
		while (++i <= data->nl_index)
			data->string[data->str_len++] = data->buffer[i];
		clean_buffer(data);
	}
}

int put_buffer_rest_in_string(t_data *data)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE && data->buffer[i] != '\n')
		i++;
	if (i < BUFFER_SIZE && data->buffer[i] == '\n')
	{
		data->nl_index = i;
		fill_string_with_buffer(data, 0);
		return (1);
	}
	else
	{
		data->nl_index = -1;
		i = -1;
		while (data->buffer[++i])
			data->string[data->str_len++] = data->buffer[i];
		return (0);
	}
}

static char *read_line(t_data *data)
{
	ssize_t bytes_read;

	data->nl_index = -1;
	if (put_buffer_rest_in_string(data))
		return (malloc_string(data));
	while (data->nl_index == -1)
	{
		bytes_read = custom_read(data);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break;
		fill_string_with_buffer(data, bytes_read);
	}
	return (malloc_string(data));
}

char *get_next_line(int fd)
{
	static t_data *data_list;
	static t_data *data;
	char *test;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data = init_data(&data_list, fd);
	if (data == NULL)
		return (NULL);

	// printf("\033[1;32m"
	// 	   "\n------------------------------ ANTES: ------------------------------\n"
	// 	   "\033[0m");
	// printf("fd: %i\n", data->fd);
	// printf("nl_index: %i\n", data->nl_index);
	// printf("str_len: %i\n", data->str_len);
	// printf("string: %s\n", data->string);
	// printf("buffer: %s\n", data->buffer);

	test = read_line(data);

	// printf("\033[1;32m"
	// 	   "\n------------------------------ DEPOIS: ------------------------------\n"
	// 	   "\033[0m");
	// printf("fd: %i\n", data->fd);
	// printf("nl_index: %i\n", data->nl_index);
	// printf("str_len: %i\n", data->str_len);
	// printf("string: %s\n", data->string);
	// printf("buffer: %s\n", data->buffer);

	return (test);
}
