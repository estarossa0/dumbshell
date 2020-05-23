/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:55 by arraji            #+#    #+#             */
/*   Updated: 2020/05/23 00:41:01 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

void	peri_excuting(t_command *cmd, t_all *all)
{
	pid_t	pid;
	int		exit_value;
	int ret;
	int	pipefd[2];

	pid = fork();
	if (pid == 0)
	{
		if (cmd->file)
		{
			dup2(cmd->fd, 1);
		}
		execve(cmd->full_path, cmd->argv, reverse_env());
	}
	else
	{
		wait((int *)&(all->exit_status));
		(all->exit_status)++;
	}
}

void	here_we_go(t_all *all)
{
	t_pipeline *pipe;

	pipe = all->pipe;
	while (pipe)
	{
		while(pipe->cmd_head)
		{
			pre_execute(pipe->cmd_head);
			peri_excuting(pipe->cmd_head, all);
			ft_fprintf(1, "command :%s\n", pipe->cmd_head->full_path);
			pipe->cmd_head = pipe->cmd_head->next;
		}
		pipe = pipe->next;
	}
}
