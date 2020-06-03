/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:55 by arraji            #+#    #+#             */
/*   Updated: 2020/06/04 00:23:18 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"
void	here_we_go(t_all *all)
{
	t_pipeline *pipe;
	int	pipefd[2];
	int	savefd[2];

	pipe = all->pipe;
	fd_saving(savefd);
	while (pipe)
	{
		while(pipe->cmd_head)
		{
			executing(pipe->cmd_head, pipefd, savefd);
			pipe->cmd_head = pipe->cmd_head->next;
		}
		pipe = pipe->next;
	}
	fd_saving(savefd);
}

void	get_data(t_all *all)
{
	ft_fprintf(1, BOLD PRINT_RED PS RESET);
	if ((all->parser.rt = get_next_line(1, &all->parser.line)) == -1)
		error(E_STANDARD, 1, NULL);
	if (all->parser.rt == 0)
	{
		kill(g_all->init_pid, SIGUSR1);
		signal(SIGUSR1, handler);
		write(1, "\n", 1);
		exit(0);
	}
	lexer(all->parser.line, &all->parser);
	parser(all->parser.line, all);
}
