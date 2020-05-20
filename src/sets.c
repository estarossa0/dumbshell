/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:51:27 by arraji            #+#    #+#             */
/*   Updated: 2020/05/20 18:59:49 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"


static	void	set_d_quotes(char *line, int index, t_parser *parser)
{
	chill(&parser->bits);
	if (AND(parser->bits, BS_Q))
		return ;
	line[index] = REMOVED;
	flip_bit(&parser->bits, BD_Q);
}

static	void	set_s_quotes(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BD_Q))
		return ;
	chill(&parser->bits);
	line[index] = REMOVED;
	flip_bit(&parser->bits, BS_Q);
}

static	void	set_space(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BS_Q) || AND(parser->bits, BD_Q))
		return ;
	else
		line[index] = WORD_SEP;
}

static	void	set_dolar(char *line, int index, t_parser *parser)
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

static	void	set_semicolon(char *line, int index, t_parser *parser)
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

static	void	set_pipe(char *line, int index, t_parser *parser)
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

static	void	set_red_to(char *line, int index, t_parser *parser)
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

static	void	set_red_from(char *line, int index, t_parser *parser)
{
	if (AND(parser->bits, BD_Q) || AND(parser->bits, BS_Q))
		return ;
	freak_out(parser->bits, line, index);
	line[index] = RED_FROM;
	BIT_ON(parser->bits, BRED_FROM);
}

void			sets(char *line, int index, t_parser *parser)
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
