/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:12:39 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/12/30 21:58:37 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void close_fds(t_command command)
{
	if (command.file_in_fd != -1)
		close(command.file_in_fd);
	if (command.file_out_fd != -1)
		close(command.file_out_fd);
	close(command.pipe_fd[0]);
	close(command.pipe_fd[1]);
}

void free_args(char **args)
{
	int i;

	i = 0;
	while (args && args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	
}

void free_all(t_command command)
{
	free(command.env.home);
	free_args(command.env.path);
}