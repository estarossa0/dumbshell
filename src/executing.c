/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 16:19:13 by arraji            #+#    #+#             */
/*   Updated: 2020/06/03 23:02:04 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

void	peri_excuting(t_command *cmd, t_all *all)
{
	pid_t	pid;
	int		exit_data;
	int ret;

	pid = fork();
	if (pid == 0)
		execve(cmd->full_path, cmd->argv, reverse_env()) == -1 ? error(E_STANDARD, 1, NULL) : 1;
	else
	{
		wait(&exit_data);
		all->exit_status = WEXITSTATUS(exit_data);
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
		dup2(savefd[0], STDIN_FILENO) == -1 ? error(E_STANDARD, 1, NULL) : 1;
		dup2(savefd[1], STDOUT_FILENO) == -1 ? error(E_STANDARD, 1, NULL) : 1;
	}
}

void	executing(t_command *cmd, int pipefd[2], int savefd[2])
{
	int		builthin;

	builthin = is_builtin(cmd->cmd_name);
	pre_execute(cmd, pipefd, savefd, builthin);
	builthin < 0 ? peri_excuting(cmd, g_all) : exec_builthin(cmd, builthin);
	post_executing(cmd, pipefd, savefd);
}
