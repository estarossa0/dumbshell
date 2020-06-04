/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_we_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:55 by arraji            #+#    #+#             */
/*   Updated: 2020/06/04 07:00:10 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

bool	here_we_go(t_all *all)
{
	t_pipeline *pipe;
	t_command	*cmd;
	int	pipefd[2];
	int	savefd[2];

	pipe = all->pipe;
	fd_saving(savefd);
	while (pipe)
	{
		cmd = pipe->cmd_head;
		while(cmd)
		{
			if (executing(cmd, pipefd, savefd) == false)
			{
				fd_saving(savefd);
				return (false);
			}
			cmd = cmd->next;
		}
		pipe = pipe->next;
	}
	fd_saving(savefd);
	return(true);
}

bool	get_data(t_all *all)
{
	ft_fprintf(1, BOLD PRINT_RED PS RESET);
	if ((all->parser.rt = get_next_line(1, &all->parser.line)) == -1)
		return (error(E_STANDARD, 1, NULL));
	if (all->parser.rt == 0)
	{
		write(1, "\n", 1);
		return (false);
	}
	if (lexer(all->parser.line, &all->parser) == false ||
	parser(all->parser.line, all) == false)
		return (false);
	return (true);
}
