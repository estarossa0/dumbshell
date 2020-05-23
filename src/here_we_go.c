/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:55 by arraji            #+#    #+#             */
/*   Updated: 2020/05/23 12:39:51 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

void	fd_saving(int savefd[3])
{
	static	int	flip = 0;

	if (flip == 0)
	{
		savefd[0] = dup(0);
		savefd[1] = dup(1);
		savefd[2] = dup(2);
	}
	else
	{
		dup2(savefd[0], 0);
		close(savefd[0]);
		dup2(savefd[1], 1);
		close(savefd[1]);
		dup2(savefd[2], 2);
		close(savefd[2]);
	}
	flip = flip == 0 ? 1 : 0;
}

void	peri_excuting(t_command *cmd, t_all *all)
{
	pid_t	pid;
	int		exit_value;
	int ret;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd->full_path, cmd->argv, reverse_env());
	}
	else
	{
		wait((int *)&(all->exit_status));
		(all->exit_status)++;
	}
}

void	post_executing(t_command *cmd, int pipefd[2], int savefd[2])
{
	if (cmd->next)
	{
		dup_close(pipefd[READ_END], STDIN_FILENO);
	}
	else
	{
		dup2(savefd[0], STDIN_FILENO);
		dup2(savefd[1], STDOUT_FILENO);
	}
}

void	here_we_go(t_all *all)
{
	t_pipeline *pipe;
	int	pipefd[2];
	int	savefd[2];
	int	first;

	pipe = all->pipe;
	fd_saving(savefd);
	while (pipe)
	{
		first = 1;
		while(pipe->cmd_head)
		{
			pre_execute(pipe->cmd_head, pipefd, savefd);
			peri_excuting(pipe->cmd_head, all);
			post_executing(pipe->cmd_head, pipefd, savefd);
			ft_fprintf(savefd[1], "command :%s\n", pipe->cmd_head->full_path);
			pipe->cmd_head = pipe->cmd_head->next;
			first = 0;
		}
		pipe = pipe->next;
	}
	fd_saving(savefd);
}
