#include <stdlib.h>
#include <stdio.h>

#include <curses.h>
#include <term.h>

int init_term()
{
	int 			ret;
	char 			*term_type = getenv("TERM");
	struct termios	term;

	if (term_type == NULL)
	{
		fprintf(stderr, "TERM must be set (see 'env').\n");
		return -1;
	}
	ret = tgetent(NULL, term_type);
	if (ret == -1)
	{
		fprintf(stderr, "Could not access to the termcap database..\n");
		return -1;
	}
	else if (ret == 0)
	{
		fprintf(stderr, "Terminal type '%s' is not defined in termcap database (or have too few informations).\n", term_type);
		return -1;
	}
	if (tcgetattr(0, &term) == -1)
	{
		fprintf(stderr, "Impossible to load term possibilities on struct termios");
		return (-1);
	}
	return 0;
}

int	voir_touche(void)
{
	char	buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
		{
			fprintf(stderr, "Very nice! this is a flecheee!\n");
			printf("%s", buffer);
		}
		else if (buffer[0] == 4)
		{
			fprintf(stderr, "U better press that Ctrl+D\n");
			return (0);
		}
		else
		{
			fprintf(stderr, "its not a flecheeeee!\n");
			return (0);
		}
	}
	return (0);
}

int		outclear(int c)
{
	putchar(c);
	return (0);
}

int	cleak(void)
{
	char *res;

	if ((res = tgetstr("cl", NULL)) == NULL)
		return (-1);
	tputs(res, 0, outclear);
	return (0);
}

int main(int argc, char **argv)
{
	int ret = init_term();

	/* On évite les warnings pour variables non utilisées. */
	(void)argc;
	(void)argv;
	if (ret == 0)
		/* Le déroulement de notre programme se fera ici. */
	{
		ret = voir_touche();
		ret += cleak();
	}
	return (ret);
}
