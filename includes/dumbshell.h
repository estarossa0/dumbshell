/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumbshell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:05:00 by arraji            #+#    #+#             */
/*   Updated: 2020/06/04 03:31:52 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMBSHELL
# define DUMBSHELL
typedef char bool;
#define true 0
#define false 1

# define _DEFAULT_SOURCE
# define D_ERROR
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/types.h>
# include "libft.h"
# include "struct.h"
# include "parser.h"
# include "error.h"
# include "errno.h"
# include "variable_expansion.h"
# include "env_handle.h"
# include "execute.h"
# include "need.h"
# include "signals_handler.h"
t_all	*g_all;
extern char **environ;
t_env		*g_env;
int			g_total_env;
bool		shit_happened;
void	checker(char *line);
void	list_checker(t_all *all);
void	list_checker2(t_all *all);
bool	here_we_go(t_all *all);
#endif
