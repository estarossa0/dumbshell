/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:04:52 by arraji            #+#    #+#             */
/*   Updated: 2020/05/19 11:34:42 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumbshell.h"

void	freak_out(int bits, char *line, int index)
{
	if (AND(bits, BPIPE))
		error(E_SYNTAX, &line[index]);
	else if (AND(bits, BD_Q))
		error(E_SYNTAX, &line[index]);
	else if (AND(bits, BS_Q))
		error(E_SYNTAX, &line[index]);
	else if (AND(bits, BRED_TO) || AND(bits, BRED_TO_APP)
	|| AND(bits, BRED_FROM))
		error(E_SYNTAX, &line[index]);
}

void	chill(int *bits)
{
	BIT_OFF(*bits, BPIPE);
	BIT_OFF(*bits, BSEMIC);
	BIT_OFF(*bits, BCHECK);
	BIT_OFF(*bits, BRED_FROM);
	BIT_OFF(*bits, BRED_TO);
	BIT_OFF(*bits, BRED_TO_APP);
}

int		error(int err, char *need)
{
	if (*need == '\0')
		need = "newline";
	else
	{
		need[0] = *need;
		need[1] = '\0';
	}
	err == E_SYNTAX ?
	ft_fprintf(1, "dumbshell: parse error near `%s'\n", need) : 1;
	/* err == E_PIPE ? ft_fprintf(1, "dumbshell: pipe in the end of input\n") : 1;
	err == E_S_Q ? ft_fprintf(1, "dumbshell: Unclosed single quote\n") : 1;
	err == E_D_Q ? ft_fprintf(1, "dumbshell: Unclosed double quote\n") : 1; */
	exit(err);
}

void	checker(char *line)
{
	int index = -1;

	write(1 , "check : ", 9);
	while (line[++index])
	{
		if (line[index] > 0)
		{
			ft_putchar_fd(line[index], 1);
			continue;
		}
		if (line[index] == WORD_SEP)
			ft_fprintf(1, "%s<word sep>%s", PRINT_RED, RESET);
		else if (line[index] == REMOVED)
			ft_fprintf(1, "%s<removed>%s", PRINT_RED, RESET);
		else if (line[index] == PIPELINE_SEP)
			ft_fprintf(1, "%s<pipeline sep>%s", PRINT_RED, RESET);
		else if (line[index] == CMD_SEP)
			ft_fprintf(1, "%s<cmd sep>%s", PRINT_RED, RESET);
		else if (line[index] == VAR)
			ft_fprintf(1, "%s<var>%s", PRINT_RED, RESET);
		else if (line[index] == RED_TO)
			ft_fprintf(1, "%s<red to>%s", PRINT_RED, RESET);
		else if (line[index] == RED_FROM)
			ft_fprintf(1, "%s<red from>%s", PRINT_RED, RESET);
		else if (line[index] == RED_TO_APP)
		{
			ft_fprintf(1, "%s<red to app>%s", PRINT_RED, RESET);
			// index++;
		}
	}
	write(1, "\n", 1);
}
