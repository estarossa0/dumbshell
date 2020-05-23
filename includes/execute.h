/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:31:39 by arraji            #+#    #+#             */
/*   Updated: 2020/05/23 12:29:29 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCUTE_H
# define EXCUTE_H
#include "dumbshell.h"
# define READ_END	0
# define WRITE_END	1
void	pre_execute(t_command *cmd, int pipefd[2], int savfd[2]);
void	dup_close(int fd1, int fd2);
#endif
