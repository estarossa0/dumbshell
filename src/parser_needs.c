#include "dumbshell.h"

static	int		get_next_word_size(t_args *current)
{
	int size;

	size = 0;
	while (current && current->c != WORD_SEP)
	{
		if (current->type == 0)
			size++;
		else
			size += ft_strlen(current->str);
		current = current->next;
	}
	return (size);
}

static	void	copy_word(t_args *current, t_args *new, int *index)
{
	int	jndex;

	jndex = 0;
	if (current->type == 0)
		new->str[(*index)++] = current->c;
	else
	{
		while (current->str[jndex])
			new->str[(*index)++] = current->str[jndex++];
	}
}

static	void	init_word(t_args *new[2], t_args *current, int need[2])
{
	int size;

	new[1] = (t_args *) ft_lstadd_back((t_list**)&new[0], malloc(sizeof(t_args)));
	size = get_next_word_size(current);
	new[1]->str = malloc(size + 1);
	new[1]->str[size] = (char)0;
	need[0] = 1;
	need[1] = 0;
}

void	reverse_args(t_args **args)
{
	t_args	*current[2];
	t_args	*new[2];
	int		needs[2];

	current[1] = *args;
	new[0] = NULL;
	needs[0] = 0;
	while (current[1])
	{
		current[0] = current[1];
		if (current[1]->c == WORD_SEP)
			needs[0] = 0;
		else if (needs[0] == 0 )
			init_word(new, current[1], needs);
		if (current[1]->c != WORD_SEP)
			copy_word(current[1], new[1], &needs[1]);
		current[1] = current[1]->next;
		if (current[0]->type == 0)
			free(current[0]);
		else
		{
			free(current[0]->str);
			free(current[0]);
		}
	}
	*args = new[0];
}

void	link_argv(t_command *cmd)
{
	int size;
	t_args	*list[2];
	int		index;

	index = 0;
	list[1] = cmd->list_args;
	size = ft_lstsize((t_list *)cmd->list_args);
	cmd->argv = (char **)malloc(sizeof(char *) * (size + 1));
	while (list[1])
	{
		list[0] = list[1];
		cmd->argv[index++] = list[1]->str;
		list[1] = list[1]->next;
		free(list[0]);
	}
	cmd->argv[index] = NULL;
}

void	reverse_parser(t_all *all)
{
	t_pipeline	*current_pipe;
	t_command	*current_cmd;

	current_pipe = all->pipe;
	while (current_pipe)
	{
		current_cmd = current_pipe->cmd_head;
		while (current_cmd)
		{
			reverse_args(&(current_cmd->list_args));
			link_argv(current_cmd);
			current_cmd = current_cmd->next;
		}
		current_pipe = current_pipe->next;
	}
}
