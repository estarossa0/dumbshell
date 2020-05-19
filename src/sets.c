/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:51:27 by arraji            #+#    #+#             */
/*   Updated: 2020/05/19 09:52:56 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"


void	set_d_quotes(char *line, int index, t_parser *parser)
{
	chill(&parser->bits);
	line[index] = REMOVED;
	flip_bit(&parser->bits, BD_Q);
}

void	set_s_quotes(char *line, int index, t_parser *parser)
{
	chill(&parser->bits);
	line[index] = REMOVED;
	flip_bit(&parser->bits, BS_Q);
}

void	set_space(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BS_Q) || AND(parser->bits, BD_Q))
		return ;
	else
		line[index] = WORD_SEP;
}

void	set_dolar(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BS_Q))
		return ;
	chill(&parser->bits);
	if (line[index + 1] == ' ' || line[index + 1] == '|'||
	line[index + 1] == ';' || line[index + 1] == '$' || line[index + 1] == 0)
		return ;
	else if (line[index + 1 ] == '\'')
		line[index] = REMOVED;
	else if (line[index + 1] == '"')
		!(AND(parser->bits, BD_Q)) ? line[index] = REMOVED : 1;
	else
		line[index] = VAR;
}

void	set_semicolon(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BD_Q) || AND(parser->bits, BS_Q))
		return ;
	freak_out(parser->bits, line, index);
	if (AND(parser->bits, BSEMIC))
		error(E_SYNTAX, &line[index]);
	else
	{
		line[index] = PIPELINE_SEP;
		BIT_ON(parser->bits, BSEMIC);
	}
}

void	set_pipe(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BD_Q) || AND(parser->bits, BS_Q))
		return ;
	freak_out(parser->bits, line, index);
	if (AND(parser->bits, BPIPE))
		error(E_SYNTAX, &line[index]);
	else
	{
		line[index] = CMD_SEP;
		BIT_ON(parser->bits, BPIPE);
	}
}

void	set_red_to(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BD_Q) || AND(parser->bits, BS_Q))
		return;
	freak_out(parser->bits, line, index);
	if (line[index + 1] == '>')
	{
		BIT_ON(parser->bits, BRED_TO_APP);
		line[index] = RED_TO_APP;
		line[index + 1] = RED_TO_APP;
	}
	else
	{
		BIT_ON(parser->bits, BRED_TO);
		line[index] = RED_TO;
	}
}

void	set_red_from(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BD_Q) || AND(parser->bits, BS_Q))
		return ;
	freak_out(parser->bits, line, index);
	line[index] = RED_FROM;
	BIT_ON(parser->bits, BRED_FROM);
}
