/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:09:52 by arraji            #+#    #+#             */
/*   Updated: 2020/05/22 15:51:09 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

static	void	init_file(t_command *command)
{
	if (command->file)
	{
		free(command->file);
		close(command->fd);
	}
}

static	char	*get_next_word(char	*line, int *index)
{
	int		save;
	char	*word;
	while(line[*index] < 0 && line[*index])
		(*index)++;
	save = *index;
	while (line[*index + 1] > 0  && line[*index + 1])
		(*index)++;
	if (!(word = ft_substr(line, save, (*index) - save + 1)))
		error(E_STANDARD, NULL);
	return (word);
}

void			parse_file(t_command *current, char *line, int *index)
{
	init_file(current);
	if (line[*index] == RED_TO)
	{
		current->file = get_next_word(line, index);
		if ((current->fd = open(current->file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
			error(E_FILE, current->file);
	}
	else if (line[*index] == RED_FROM)
	{
		current->file = get_next_word(line, index);
		if ((current->fd = open(current->file, O_RDONLY)) < 0)
			error(E_FILE, current->file);
	}
	else if (line[*index] == RED_TO_APP)
	{
		current->file = get_next_word(line, index);
		if ((current->fd = open(current->file, O_WRONLY | O_CREAT | O_APPEND, 0644)) < 0)
			error(E_FILE, current->file);
	}
}
