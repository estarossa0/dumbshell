/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:05:20 by arraji            #+#    #+#             */
/*   Updated: 2020/05/20 18:40:24 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT
# define STRUCT

typedef	struct	s_parser
{
	int		bits;
	char	*line;
	int		rt;
}				t_parser;

typedef	struct	s_args
{
	struct	s_args	*next;
	char			c;
	char			*str;
	int				type;
}				t_args;

typedef	struct	s_command
{
	struct	s_command	*next;
	char				*cmd;
	char				**args;
	struct	s_args		*list_args;
	char				*path;
	int					fd;
	char				*file;
	char				read_type;
	int					relation;
}				t_command;

typedef	struct s_pipeline
{
	struct	s_pipeline	*next;
	struct	s_command	*cmd_head;
	struct	s_command	*cmd;
}				t_pipeline;

typedef	struct	s_all
{
	unsigned char	exit_status;
	t_parser		parser;
	t_pipeline		*pipe;
}				t_all;

typedef	struct	s_env
{
	struct	s_env	*next;
	char	*var;
	char	*value;
	char	*full_var;
}				t_env;
#endif
