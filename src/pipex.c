/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:19:11 by znicola           #+#    #+#             */
/*   Updated: 2025/01/06 23:31:32 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static pid_t exec_cmd1(t_prgpar_data, int *pipe_fd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		data_cleanup(&data);
		exit(1);
	}
	if (pid == 0)
	{
		dup2(data.infile, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(data.infile);
		close(data.outfile);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(data.cmd1[0], data.cmd1, envp);
		perror("execve cmd1");
		exit(1);
	}
	return(pid);
}

static pid_t exec_cmd2(t_prgpar data, int *pipe_fd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		data_cleanup(&data);
		exit(1);
	}
	if (pid == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(data.outfile, STDOUT_FILENO);
		close(data.infile);
		close(data.outfile);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(data.cmd2[0], data.cmd2, envp);
		perror("execve cmd2");
		exit(1);
	}
	return(pid);
}


void	pipex(t_prgpar data, char **envp)
{
	int	pipe_fd[2];
	pid_t pid1;
	pid_t pid2;
	
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		data_cleanup(&data);
		exit(1);
	}
	
	pid1 = exec_cmd1(data, pipe_fd, envp);
	pid2 = exec_cmd2(data, pipe_fd, envp);

	close(pipe_fd[0]);
	close(pipe_fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
