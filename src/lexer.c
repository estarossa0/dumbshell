/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:32 by arraji            #+#    #+#             */
/*   Updated: 2020/06/04 07:48:54 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

static	bool	check_before(char current, int *data)
{
	if (current == '|')
	{
		if (AND(*data, BCHECK))
			return (error(E_SYNTAX, 1, &current));
		if (AND(*data, BPIPE))
			return (error(E_SYNTAX, 1, &current));
	}
	else if (current == ';')
		if (AND(*data, BSEMIC))
			return (error(E_SYNTAX, 1, &current));
	return (0);
}

bool			lexer(char *line, t_parser *parser)
{
	int	i;

	i = -1;
	chill(&parser->bits);
	while (line[++i])
	{
		if (check_before(line[i], &parser->bits) == false ||
		sets(line, i, parser) == false)
			return (false);
	}
	if (freak_out(parser->bits, line, i) == false)
		return(false);
	chill(&parser->bits);
	return (true);
}
