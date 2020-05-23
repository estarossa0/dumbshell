/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:05:12 by arraji            #+#    #+#             */
/*   Updated: 2020/05/22 15:51:22 by arraji           ###   ########.fr       */
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
# define	CNULL			-10
void	get_data(t_all *);
void	parser(char *line, t_all *all);
void	lexer(char *, t_parser *parser);
void	sets(char *line, int index, t_parser *parser);
void	add_word(t_args **list, char *word, int type);
void	parse_file(t_command *current, char *line, int *index);
void	reverse_parser(t_all *all);
#endif
