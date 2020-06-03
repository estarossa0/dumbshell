/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:28 by arraji            #+#    #+#             */
/*   Updated: 2020/06/04 00:30:55 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

void	init(t_all *all)
{
	all->parser.bits = 64;
	all->parser.line = NULL;
	all->parser.rt = 1;
	all->pipe = NULL;
	g_env = NULL;
	g_total_env = 0;
	g_all = all;
	all->init_pid = getpid();
	is_exit = 0;
	all->exit_status = 0;
	g_pid = 0;
	init_env();
	// g_env->next->next->next->next = NULL;

}

int main(void)
{
	t_all	all;
	int		exit_data;

	init(&all);
	signal(SIGUSR1, handler);
	while (1)
	{
		signal(SIGINT, handler);
		if ((g_pid = fork()) == -1)
			error(E_STANDARD, 1, NULL);
		if (g_pid == 0)
		{
			signal(SIGINT, child_handler);
			get_data(&all);
			here_we_go(&all);
			exit(all.exit_status);
		}
		else
		{
			wait(&exit_data);
			all.exit_status = WEXITSTATUS(exit_data);
			if (WIFSIGNALED(exit_data))
				WTERMSIG(exit_data) != SIGINT ? exit(128 + WTERMSIG(exit_data)) : 1;
			else if (is_exit)
				exit(all.exit_status);
		}
	}
}
