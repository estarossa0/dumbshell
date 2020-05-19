/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:28 by arraji            #+#    #+#             */
/*   Updated: 2020/05/19 11:41:33 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

void	init(t_all *all)
{
	all->parser.bits = 64;
	all->parser.line = NULL;
	all->parser.rt = 1;
	all->pipe = NULL;
}

int main(void)
{
	t_all	all;

	init(&all);
	get_data(&all);
}
