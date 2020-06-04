/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 00:11:18 by arraji            #+#    #+#             */
/*   Updated: 2020/06/04 07:25:38 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		shit_happened = 1;
	}
}

void	child_handler(int sig)
{
	write(1, "\n", 2);
	exit(128 + sig);
}
