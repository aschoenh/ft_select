/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:11:01 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/14 19:40:34 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void	handler(int action, t_select infos)
{
	reset_config(infos);
	if (action == STOP)
	{
//		free_all();
		exit(EXIT_SUCCESS);
	}
	else if (action == SUSPEND)
	{
		// voir comment bien suspendre le prrogramme + probleme de comment recuperer les signaux (par exemple, fg, une fois le programme suspendu?
	}
}

void		sig_handler(int signo, t_select infos)
{
	if (signo == SIGTSTP)
		handler(SUSPEND, infos);
	else if (signo == SIGINT || signo == SIGQUIT || signo == SIGSTOP
				|| signo == SIGKILL || signo == SIGABRT)
		handler(STOP, infos);
	else if (signo == SIGCONT)
		// reprendre le programme : refaire la config et renit les sig? 
		ft_printf(" ");
	else if (signo == SIGWINCH)
		change_display();
}
