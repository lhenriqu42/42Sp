/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:46:46 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/12/30 22:02:09 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void set_dup2(int fd_in, int fd_out)
{
    dup2(fd_in, STDIN_FILENO);
    dup2(fd_out, STDOUT_FILENO);
}

static void change_input_and_output(t_command command, int type)
{
    if (type == FIRST)
        set_dup2(command.file_in_fd, command.pipe_fd[WRITE_FD]);
    else if (type == LAST)
        set_dup2(command.pipe_fd[READ_FD], command.file_out_fd);
}

static char *error_message(char *cmd, int *return_code)
{
    if (!cmd || access(cmd, F_OK) != 0)
    {
        *return_code = 127;
        return (C_ERROR "command not found" C_BREAK);
    }
    else if (access(cmd, X_OK) != 0)
    {
        *return_code = 126;
        return (C_ERROR "permission denied" C_BREAK);
    }
    return ("");
}

void exec_process(t_command command, char *cmd, int type)
{
    int return_code;
    char *new_cmd;
    char **args;

    return_code = 1;
    if ((type == FIRST && command.file_in_fd != 1) || (type == LAST && command.file_out_fd != 1))
    {
        args = ft_split(cmd, ' ');
        new_cmd = handle_path(args[0], command.env);
        if (new_cmd && access(new_cmd, F_OK | X_OK) == 0)
        {
            change_input_and_output(command, type);
            close_fds(command);
            execve(new_cmd, args, command.envp);
        }
        ft_printf_fd(2, "%s: %s\n", error_message(new_cmd, &return_code), args[0]);
        free(new_cmd);
        free_args(args);
    }
    close_fds(command);
    free_all(command);
	exit(return_code);
}
