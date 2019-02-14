#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

int				init_term(void)
{
	char		*buffer;
	char		*term_type;
	int			ret;

	if ((term_type = getenv("TERM")) == NULL)
	{
		perror("c pa dans env, bolos, set l");
		return (-1);
	}
	printf("mon terminal : %s\n", term_type);
	ret = tgetent(NULL, term_type);
	printf("mon ret : %d\n", ret);
	if (ret == -1)
	{
		perror("no access to termcap database bolos");
		return (-1);
	}
	if (ret == 0)
	{
		perror("pas dinfos sur le terminal");
		return (-1);
	}
	return (0);
}

int				main(void)
{
	int ret = init_term();

	if (ret == 0)
	{
		return (ret);
	}
	return (ret);
}
