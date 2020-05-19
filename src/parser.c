/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:36 by arraji            #+#    #+#             */
/*   Updated: 2020/05/19 11:53:36 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

void	parse_file(char *line, char *new, int *indexs)
{
	if (line[indexs[0]] == RED_TO_APP)
		indexs[0]++;
	new[indexs[1]++] = line[indexs[0]++];
	while(line[indexs[0]] == WORD_SEP)
			indexs[0]++;
	while (line[indexs[0]] != WORD_SEP && line[indexs[0]] != '\0')
	{
		if (line[indexs[0]] != REMOVED)
			new[indexs[1]++] = line[indexs[0]];
		indexs[0]++;
	}
}

/*
** [0] -> line index
** [1] -> new index
*/

char	*new_line(char *line)
{
	int		indexs[2];
	char	*new;

	indexs[0] = -1;
	indexs[1] = 0;
	new = malloc(ft_strlen(line));
	ft_bzero(new, ft_strlen(line));
	while(line[++(indexs[0])])
	{
		if (line[(indexs[0])] == REMOVED)
			continue ;
		else if (line[indexs[0]] == RED_FROM || line[indexs[0]] == RED_TO
		|| line[indexs[0]] == RED_TO_APP)
			parse_file(line, new, indexs);
		else
		{
			new[indexs[1]++] = line[indexs[0]];
		}
	}
	free(line);
	return (new);
}

void	parse_commands(t_all *all)
{

}

void	parser(t_all *all)
{
	all->parser.line = new_line(all->parser.line);

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
		parser(all);
	}

}
