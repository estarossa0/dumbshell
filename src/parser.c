/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:36 by arraji            #+#    #+#             */
/*   Updated: 2020/05/23 16:36:48 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

static	void	init_list(t_command **current, t_all *all)
{
	if (all->pipe == NULL)
	{
		ft_lstadd_back((t_list **)&(all->pipe), malloc(sizeof(t_pipeline)));
		all->pipe->cmd_head = NULL;
		*current = (t_command *)ft_lstadd_back((t_list **)&(all->pipe->cmd_head), malloc(sizeof(t_command)));
		(*current)->list_args = NULL;
		(*current)->file = NULL;
		(*current)->read_type = 0;
	}
}

static	void	switch_current(t_command **current, char *line, int *index, t_all *all)
{
	t_pipeline	*pipe;

	if (line[*index] == PIPELINE_SEP)
	{
		pipe = (t_pipeline*)ft_lstadd_back((t_list **)&(all->pipe), malloc(sizeof(t_pipeline)));
		pipe->cmd_head = NULL;
		*current = (t_command *)ft_lstadd_back((t_list **)&(pipe->cmd_head), malloc(sizeof(t_command)));
		(*current)->read_type = 0;
	}
	else
	{
		*current = (t_command *)ft_lstadd_back((t_list **)current, malloc(sizeof(t_command)));
		(*current)->read_type = 1;
	}
	(*current)->list_args = NULL;
	(*current)->file = NULL;
	(*index)++;
}


void	add_word(t_args **list, char *word, int type)
{
	t_args	*current;

	current = (t_args *)ft_lstadd_back((t_list **)list, malloc(sizeof(t_args)));
	current->type = type;
	if (type == 0)
		current->c = *word;
	else if (type == 1)
	{
		current->str = word;
		current->c = CNULL;
	}
}


void			parser(char *line, t_all *all)
{
	int			index;
	t_command	*current;

	index = -1;
	while (line[++index])
	{
		init_list(&current, all);
		if (line[index] == REMOVED)
			continue ;
		else if (line[index] == RED_FROM || line[index] == RED_TO
		|| line[index] == RED_TO_APP)
			parse_file(current, line, &index);
		else if (line[index] == VAR)
			variable_expansion(line, &index, current);
		else if (line[index] == CMD_SEP || line[index] == PIPELINE_SEP)
			switch_current(&current, line, &index, all);
		else
			add_word(&current->list_args, &line[index], 0);
	}
	reverse_parser(all);
}
