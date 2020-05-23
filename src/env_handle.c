#include "dumbshell.h"

void	init_env()
{
	int		index;
	int		split;
	t_env	*current;

	index = 0;
	while(environ[index])
	{
		split = 0;
		current = (t_env*)ft_lstadd_back((t_list**)&g_env, malloc(sizeof(t_env)));
		current->full_var =  ft_strdup(environ[index]);
		while (environ[index][split] != '=')
			split++;
		current->key = ft_substr(current->full_var, 0, split);
		current->value = ft_substr(current->full_var, split + 1,
		ft_strlen(current->full_var) - split);
		index++;
		g_total_env++;
	}
}

char	**reverse_env()
{
	t_env	*curr;
	char	**env;
	int		index;

	index = 0;
	curr = g_env;
	env = (char **)malloc(sizeof(char *) * (g_total_env + 1));
	while (curr)
	{
		env[index] = curr->full_var;
		curr = curr->next;
		index++;
	}
	env[index] = NULL;
	return (env);
}
