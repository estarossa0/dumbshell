/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 00:11:18 by arraji            #+#    #+#             */
/*   Updated: 2020/06/04 00:24:59 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

void	handler(int sig)
{
	write(1, "F", 1);
	if (sig == SIGINT)
	{
		signal(SIGINT, SIG_IGN);
		kill(g_pid, SIGINT);
	}
	else if (sig == SIGUSR1)
		is_exit = 1;
}

void	child_handler(int sig)
{
	write(1, "\n", 2);
	exit(128 + sig);
}
