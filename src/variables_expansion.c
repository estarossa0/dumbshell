#include "dumbshell.h"

char	*get_var_value(char *var_name)
{
	t_env	*curr;

	curr = env;
	while (curr)
	{
		if (ft_strcmp(var_name, curr->var) == 0)
			return(curr->value);
		curr = curr->next;
	}
	return (NULL);
}

void	variable_expansion(char *line, int *index, t_command *current)
{
	char	*var_name;
	int		save;
	char	*var_value;
	(*index)++;
	save = *index;
	while(ft_isalnum(line[*index]) || line[*index] == '_')
		(*index)++;
	var_name = ft_substr(line, save, (*index) - save);
	var_value = get_var_value(var_name);
	if (var_value)
		add_word(&current->list_args, var_value, 1);
}
