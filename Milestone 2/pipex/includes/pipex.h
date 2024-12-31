#ifndef PIPEX_H
# define PIPEX_H

# include "../libs/libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

// COLORS
# define C_SUCCESS "\033[32;3m"
# define C_ERROR "\033[31;1m"
# define C_BREAK "\033[0m"

// ERRORS
# define E_INVALID_ARGS 1

// MACROS
# define PID_CHILD 0

enum e_fd
{
	READ_FD = 0,
	WRITE_FD
};

enum e_process
{
	FIRST,
	LAST
};

typedef struct s_env
{
	char	*home;
	char	**path;
}	t_env;

typedef struct s_command
{
	int		file_in_fd;
	int		file_out_fd;
	int     pipe_fd[2];
	int		pid[2];
	char	*cmd1;
	char	*cmd2;
	char	**envp;
	t_env	env;
}	t_command;

t_env	get_env_variables(char **envp);
void	exec_process(t_command command, char *cmd, int type);
char	*handle_path(char*cmd, t_env env);
void	close_fds(t_command command);
void	free_all(t_command command);
void	free_args(char** args);



#endif