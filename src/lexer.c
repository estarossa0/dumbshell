/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:32 by arraji            #+#    #+#             */
/*   Updated: 2020/05/19 11:38:41 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

void	check_before(char current, int *data)
{
	if (current == '|')
	{
		AND(*data, BCHECK) ? error(E_SYNTAX, &current) : 1;
		AND(*data, BPIPE) ? error(E_SYNTAX, &current) : 1;
	}
	else if (current == ';')
	{
		AND(*data, BSEMIC) ? error(E_SYNTAX, &current) : 1;
	}
}

void	sets(char *line, int index, t_parser *parser)
{
	if (line[index] < 0)
		return ;
	else if (line[index] == '|')
		set_pipe(line, index, parser);
	else if (line[index] == '\'')
		set_s_quotes(line, index, parser);
	else if (line[index] == '"')
		set_d_quotes(line, index, parser);
	else if (line[index] == ';')
		set_semicolon(line, index, parser);
	else if (line[index] == '$')
		set_dolar(line, index, parser);
	else if (line[index] == ' ')
		set_space(line, index, parser);
	else if (line[index] == '>')
		set_red_to(line, index, parser);
	else if (line[index] == '<')
		set_red_from(line, index, parser);
	else
		chill(&parser->bits);
}

void	lexer(char *line, t_parser *parser)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		check_before(line[i], &parser->bits);
		sets(line, i, parser);
	}
	freak_out(parser->bits, line, i);
	chill(&parser->bits);
}
