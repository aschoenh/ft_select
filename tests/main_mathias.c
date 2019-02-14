/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporzier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:41:58 by mporzier          #+#    #+#             */
/*   Updated: 2019/02/14 15:09:03 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>
#include <strings.h>

int              main(int ac, char **av, char **env)
{
	char           *name_term;
	struct termios term;
	char *res;
	char *area;
	char buffer[64] = {0};

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
	while (1)
	{
		read(0, buffer, sizeof(buffer));
		if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 'D')
		{
			res = tgetstr("le", NULL);
			tputs(res, 1, putchar);
		}
		else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 'C')
		{
			res = tgetstr("nd", NULL);
			tputs(res, 1, putchar);
		}
		else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 'A')
		{
			res = tgetstr("up", NULL);
			tputs(res, 1, putchar);
		}
		else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 'B')
		{
			res = tgetstr("do", NULL);
			tputs(res, 1, putchar);
		}
		else if (buffer[0] == 127)
		{
			res = tgetstr("le", NULL);
			tputs(res, 1, putchar);
			res = tgetstr("dc", NULL);
			tputs(res, 1, putchar);
		}
		else
		{
			printf("%c", buffer[0]);
		}
		fflush(stdout);
	}
	return (0);
}
