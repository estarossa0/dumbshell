#ifndef NEED_H
# define NEED_H
#include "dumbshell.h"
void	dup_close(int fd1, int fd2);
void	fd_saving(int savefd[2]);
int		is_builtin(char *cmd);
int		find_replace(t_env *var);
#endif
