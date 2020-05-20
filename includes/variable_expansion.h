#ifndef VAR_HANDLE
# define VAR_HANDLE
char	*get_var_value(char *var_name);
void	variable_expansion(char *line, int *index, t_command *current);
#endif
