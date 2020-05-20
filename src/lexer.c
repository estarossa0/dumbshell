/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:32 by arraji            #+#    #+#             */
/*   Updated: 2020/05/20 17:55:32 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

static	void	check_before(char current, int *data)
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

void			lexer(char *line, t_parser *parser)
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
