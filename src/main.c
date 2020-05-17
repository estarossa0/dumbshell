#include "dumbshell.h"

int main(void)
{
	char *line;
	int rt;

	rt = 1;
	while (rt == 1)
	{
		ft_fprintf(1, PS);
		rt = get_next_line(1, &line);

	}
}
