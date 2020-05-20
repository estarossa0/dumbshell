/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:28 by arraji            #+#    #+#             */
/*   Updated: 2020/05/20 18:18:08 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"


void	init(t_all *all)
{
	all->parser.bits = 64;
	all->parser.line = NULL;
	all->parser.rt = 1;
	all->pipe = NULL;
	env = NULL;
	init_env();
}

void	get_data(t_all *all)
{
	char *new;

	while (all->parser.rt == 1)
	{
		ft_fprintf(1, PS);
		all->parser.rt = get_next_line(1, &all->parser.line);
		lexer(all->parser.line, &all->parser);
		checker(all->parser.line);
		parser(all->parser.line, all);
		list_checker(all);
		all->pipe = NULL;
	}

}
int main(void)
{
	t_all	all;

	init(&all);
	get_data(&all);
}
