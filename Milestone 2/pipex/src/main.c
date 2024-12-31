/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:22:25 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/12/30 22:03:57 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void init(t_command *command, int argc, char *argv[], char *envp[])
{
    command->file_in_fd = open(argv[1], O_RDONLY);
    if (command->file_in_fd < 0)
        perror(C_ERROR "invalid input file" C_BREAK);
    command->file_out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (command->file_out_fd < 0)
        perror(C_ERROR "invalid output file" C_BREAK);
    command->env = get_env_variables(envp);
    command->cmd1 = argv[2];
    command->cmd2 = argv[3];
    command->envp = envp;
}

static void exec_commands(t_command *command)
{
    pipe(command->pipe_fd);
    command->pid[0] = fork();
    if (command->pid[0] == PID_CHILD)
        exec_process(*command, (*command).cmd1, FIRST);

    command->pid[1] = fork();
    if (command->pid[1] == PID_CHILD)
        exec_process(*command, (*command).cmd2, LAST);
}

int main(int argc, char *argv[], char *envp[])
{
    t_command command;
    int return_code;

    if (argc != 5)
    {
        ft_printf_fd(2, C_ERROR "Expected: ./pipex <file_in> <cmd1> <cmd2> <file_out>\n" C_BREAK);
        return (1);
    }
    init(&command, argc, argv, envp);
    exec_commands(&command);
    if (command.file_in_fd != -1)
		close(command.file_in_fd);
	if (command.file_out_fd != -1)
		close(command.file_out_fd);
	close(command.pipe_fd[0]);
	close(command.pipe_fd[1]);
	waitpid(command.pid[0], &return_code, 0);
	waitpid(command.pid[1], &return_code, 0);
	free_all(command);
	return ((return_code >> 8) & 0xFF);
}
