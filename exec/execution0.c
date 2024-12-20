#include "../includes/minishell.h"

void	execute_0_pipe(t_cmd *cmd)
{
	execve(cmd->path, cmd->args, NULL);
	exit(0);
}
void	is_the_child(t_cmd *cmd, int *pipeline, int fd[2])
{
	if (*pipeline != -1)
	{
		dup2(*pipeline, STDIN_FILENO);
		close(*pipeline);
	}
	if (cmd->next)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	execve(cmd->path, cmd->args, NULL);
	exit(1);
}

void	ft_go_execute(t_cmd *cmd)
{
	int fd[2];
	int pipeline;
	pid_t fok;
	t_cmd *tmp;

	if (!cmd)
		return ;
	tmp = NULL;
	tmp = cmd;
	if (cmd->pipe == false)
	{
		fok = fork();
		if (fok == -1)
			perror("ERROR in minishell\n");
		else if (fok == 0)
			execute_0_pipe(tmp);
		else
			waitpid(fok, NULL, 0);
	}
	else
	{
		pipeline = -1;
		while (tmp)
		{
			if (pipe(fd) == -1)
			{
				perror("Invalid file descriptor\n");
				return ;
			}
			fok = fork();
			if (fok == -1)
				perror("eERROR in MInishell\n");
			else if (fok == 0)
				is_the_child(tmp, &pipeline, fd);
			else
			{
				if (pipeline != -1)
					close(pipeline);
				pipeline = dup(fd[0]);
				close(fd[1]);
				close(fd[0]);
				tmp = tmp->next;
				waitpid(fok, NULL, 0);
			}
		}
	}
}