/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 06:13:12 by arraji            #+#    #+#             */
/*   Updated: 2020/06/04 00:33:11 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

static	void	b_echo(t_command *cmd)
{
	int		index;
	int		save;

	save = 0;
	index = 1;
	if (!ft_strcmp(cmd->argv[1], "-n") && index++)
		save = 1;
	while (cmd->argv[index])
	{
		ft_fprintf(1, "%s", cmd->argv[index++]);
		cmd->argv[index] != NULL ? ft_fprintf(1, " ") : 1;
	}
	save ? 1 : write(1, "\n", 1);
	g_all->exit_status = 0;
}

static	void	b_cd(t_command *cmd)
{
	int len;
	char	*home;
	len = ft_tablen(cmd->argv);
	if (len > 2)
		error(E_ARGS, 1, cmd->cmd_name);
	if	(len == 1)
	{
	vibe_check2
		home = get_var_value("HOME");
		if (home)
		{
			if (chdir(home) == -1)
				error(E_CD, 1, home);
		}
		else
			error(E_CD_HOME, 1, NULL);
	}
	else if (chdir(cmd->argv[1]) == -1)
		error(E_CD, 1, cmd->argv[1]);
}

static	void	b_pwd(t_command *cmd)
{
	char	*dir;

	if (ft_tablen(cmd->argv) != 1)
		error(E_ARGS, 1, cmd->cmd_name);
	dir = getcwd(NULL, 0);
	ft_fprintf(1, "%s\n", dir);
	free(dir);
}


static	void	b_export(t_command *cmd)
{
	int		index;
	t_env	*curr;

	index = 0;
	if (ft_tablen(cmd->argv) == 1)
		print_env();
	else
	{
		while (cmd->argv[++index])
		{
			curr = new_var(cmd->argv[index]);
			if (ft_strlen(curr->key) == 0)
				error(E_NOT_VAL, 1, curr->full_var);
			if (find_replace(curr))
				continue ;
			ft_lstadd_back((t_list **)&g_env, (void *)curr);
		}
	}
}

static	void	b_env(t_command *cmd)
{
	if (ft_tablen(cmd->argv) != 1)
		error(E_ARGS, 1, cmd->cmd_name);
	print_env();
}

static	void	b_unset(t_command *cmd)
{
	int		index;
	int		jndex;
	t_env	*curr;

	jndex = 0;
	curr = g_env;
	while (curr)
	{
		index = 0;
		while (cmd->argv[++index])
			if (!ft_strcmp(cmd->argv[index], curr->key))
			{
				ft_lstdel_index((t_list**)&g_env, (void (*)(t_list *))del_env, jndex);
				return ;
			}
		jndex++;
		curr = curr->next;
	}
}

static	void	b_exit(t_command *cmd)
{
	int		index;

	index = 0;
	if (ft_tablen(cmd->argv) > 2)
		error(E_ARGS, 1, cmd->cmd_name);
	while (cmd->argv[1] && cmd->argv[1][index])
		if (!ft_isdigit(cmd->argv[1][index++]))
			error(E_EXIT_ARG, 2, cmd->argv[1]);
	kill(g_all->init_pid, SIGUSR1);
	cmd->argv[1] == NULL ? exit(0) : exit(ft_atoi(cmd->argv[1]));
}

void	exec_builthin(t_command *cmd, int builthin)
{
	void	(*builthin_functions[7])(t_command *cmd) = {b_echo, b_cd, b_pwd, b_export, b_env, b_unset, b_exit};

	builthin_functions[builthin](cmd);
}
