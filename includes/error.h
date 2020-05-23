/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:05:04 by arraji            #+#    #+#             */
/*   Updated: 2020/05/22 13:49:53 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR
#define ERROR
# define	E_STANDARD	1
# define	E_SYNTAX		2
# define	E_FILE		3
# define	E_NOCMD		4
# define	E_WPATH		5
# define	E_ISDIR		6
int		error(int error, char *need);
void	freak_out(int bits, char *line, int index);
void	chill(int *bits);
#endif
