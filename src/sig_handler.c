/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:11:01 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/21 16:35:22 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void		handler(t_handle action)
{
	reset_config();
	if (action == STOP)
	{
//		free_all();
		exit(EXIT_SUCCESS);
	}
	else if (action == SUSPEND)
	{
		// voir comment bien suspendre le prrogramme + probleme de comment recuperer les signaux (par exemple, fg, une fois le programme suspendu?
		signal(SIGTSTP, SIG_DFL);
		ioctl(2, TIOCSTI, "\x1A");
	}
}

void		sig_handler(int signo)
{
	if (signo == SIGTSTP)
		handler(SUSPEND);
	else if (signo == SIGINT || signo == SIGQUIT || signo == SIGSTOP
				|| signo == SIGKILL || signo == SIGABRT || signo == SIGILL
				|| signo == SIGPIPE || signo == SIGFPE || signo == SIGSYS
				|| signo == SIGTRAP || signo == SIGHUP || signo == SIGBUS
				/*|| signo == SIGSEGV */|| signo == SIGALRM || signo == SIGTERM
				|| signo == SIGUSR1 || signo == SIGUSR2)
		handler(STOP);
	else if (signo == SIGCONT)
	{
		// reprendre le programme : refaire la config et renit les sig? 
		init_configuration();
		init_sig_handler();
		change_display();
	}
	else if (signo == SIGWINCH)
		change_display();
}
