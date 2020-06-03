/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:31:39 by arraji            #+#    #+#             */
/*   Updated: 2020/06/02 19:02:02 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCUTE_H
# define EXCUTE_H
#include "dumbshell.h"
# define READ_END	0
# define WRITE_END	1
void	pre_execute(t_command *cmd, int pipefd[2], int savfd[2], int builthin);
void	executing(t_command *cmd, int pipefd[2], int savefd[2]);
void	exec_builthin(t_command *cmd, int builthin);
#endif
