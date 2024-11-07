/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:28:40 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/11/07 17:33:52 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*malloc_string(t_data *data)
{
	char	*str;
	int		i;

	i = -1;
	str = (char *)malloc(data->str_len + 1);
	while (++i <= data->str_len)
		str[i] = data->string[i];
	return (str);
}

static ssize_t	custom_read(t_data **data)
{
	ssize_t	bytes_read;
	int		i;

	i = -1;
	while (++i < BUFFER_SIZE)
		(*data)->buffer[i] = '\0';
	bytes_read = read((*data)->fd, (*data)->buffer, BUFFER_SIZE);
	i = 0;
	while (i < bytes_read && (*data)->buffer[i] != '\n')
		i++;
	if (i < bytes_read && (*data)->buffer[i] == '\n')
		(*data)->nl_index = i;
	else
		(*data)->nl_index = -1;
	return (bytes_read);
}

void	clean_buffer(t_data **data)
{
	int		i;
	int		j;
	char	temp[BUFFER_SIZE];

	i = 0;
	j = (*data)->nl_index + 1;
	while (j < BUFFER_SIZE)
	{
		temp[i] = (*data)->buffer[j];
		i++;
		j++;
	}
	while (i < BUFFER_SIZE)
		temp[i++] = '\0';
	i = 0;
	while (i < BUFFER_SIZE)
		(*data)->buffer[i++] = temp[i];
}

void	handle_buffer(t_data **data)
{
	int		i;

	i = 0;
	while (i < BUFFER_SIZE && (*data)->buffer[i] != '\n')
		i++;
	if (i < BUFFER_SIZE && (*data)->buffer[i] == '\n')
		(*data)->nl_index = i;
	else
		(*data)->nl_index = -1;
}

void	fill_string_with_buffer(t_data **data, ssize_t bytes_read)
{
	int	i;

	i = -1;
	if (bytes_read == -2)
		handle_buffer(data);
	if ((*data)->nl_index == -1)
	{
		while (++i < bytes_read)
			(*data)->string[(*data)->str_len++] = (*data)->buffer[i];
	}
	else
	{
		while (++i <= (*data)->nl_index)
			(*data)->string[(*data)->str_len++] = (*data)->buffer[i];
		clean_buffer(data);
	}
}

static char	*read_line(t_data **data)
{
	ssize_t	bytes_read;
	int		i;

	i = -1;
	bytes_read = -2;
	while (++i < ARRAY_SIZE)
		(*data)->string[i] = '\0';
	(*data)->str_len = 0;
	while ((*data)->nl_index == -1)
	{
		fill_string_with_buffer(data, bytes_read);
		bytes_read = custom_read(data);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
	}
	return (malloc_string(*data));
}

char	*get_next_line(int fd)
{
	static t_data	*data;
	char			*test;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (init_data(&data, fd) == NULL)
		return (NULL);
	printf("\n------------------------------ ANTES: ------------------------------\n");
	printf("fd: %i\n", data->fd);
	printf("nl_index: %i\n", data->nl_index);
	printf("str_len: %i\n", data->str_len);
	printf("string: %s\n", data->string);
	printf("buffer: %s\n", data->buffer);
	test = read_line(&data);
	printf("\n------------------------------ DEPOIS: ------------------------------\n");
	printf("fd: %i\n", data->fd);
	printf("nl_index: %i\n", data->nl_index);
	printf("str_len: %i\n", data->str_len);
	printf("string: %s\n", data->string);
	printf("buffer: %s\n", data->buffer);
	return (test);
}
