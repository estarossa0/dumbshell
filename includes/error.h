/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:05:04 by arraji            #+#    #+#             */
/*   Updated: 2020/05/20 17:41:59 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR
#define ERROR
# define	E_STANDARD	6
# define	E_SYNTAX	1
# define	E_PIPE		2
# define	E_D_Q		3
# define	E_S_Q		4
# define	E_FILE		5
int		error(int error, char *need);
void	freak_out(int bits, char *line, int index);
void	chill(int *bits);
#endif
