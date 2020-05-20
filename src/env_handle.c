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
		current = (t_env*)ft_lstadd_back((t_list**)&env, malloc(sizeof(t_env)));
		current->full_var =  ft_strdup(environ[index]);
		while (environ[index][split] != '=')
			split++;
		current->var = ft_substr(current->full_var, 0, split);
		current->value = ft_substr(current->full_var, split + 1,
		ft_strlen(current->full_var) - split);
		index++;
	}
}
