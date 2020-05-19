/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:05:12 by arraji            #+#    #+#             */
/*   Updated: 2020/05/19 09:25:19 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define	PARSER_H
# define	PS "dumbshell$> "
# define PRINT_RED		"\033[1;31m"
# define PRINT_GR		"\033[1;32m"
# define RESET			"\033[0m"
# define	BS_Q			1
# define	BD_Q			2
# define	BBACKSLASH		4
# define	BDOLAR			8
# define	BPIPE			16
# define	BSEMIC			32
# define	BCHECK			64
# define	BRED_TO			128
# define	BRED_TO_APP		256
# define	BRED_FROM		512
# define	WORD_SEP		-69
# define	REMOVED			-2
# define	PIPELINE_SEP	-3
# define	CMD_SEP			-4
# define	VAR				-5
# define	RED_TO			-6
# define	RED_FROM		-7
# define	RED_TO_APP		-9
void	get_data(t_all *);
void	lexer(char *, t_parser *parser);
void	set_d_quotes(char *line, int index, t_parser *parser);
void	set_s_quotes(char *line, int index, t_parser *parser);
void	set_space(char *line, int index, t_parser *parser);
void	set_dolar(char *line, int index, t_parser *parser);
void	set_semicolon(char *line, int index, t_parser *parser);
void	set_pipe(char *line, int index, t_parser *parser);
void	set_red_to(char *line, int index, t_parser *parser);
void	set_red_from(char *line, int index, t_parser *parser);
#endif
