#ifndef VAR_HANDLE
# define VAR_HANDLE
void	variable_expansion(char *line, int *index, t_command *current);
char	*get_var_value(char *var_name);
#endif
