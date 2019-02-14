/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_configuration.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:40:17 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/14 19:36:24 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"
#include <curses.h>
#include <term.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>

/*
 * askip c'est mieux de pas utiliser 1 pour atty, sinon ca bug quand ont passe "ft_select x y z" en argument d'une autre fonction style LS. la library terminfo adaptee au terminal est chargee, sinon erreur et exit.
 */

static void		get_config(char *term_type)
{
	int			is_term;
	
	if (!(isatty(2)))
		errors_and_exit(TERMIN);
	is_term = tgetent(NULL, term_type);
	if ((is_term = tgetent(NULL, term_type)) < 1)
		if (is_term == 0)
			errors_and_exit(NO_ENTRY);
		errors_and_exit(NOT_FOUND);
	
}

/*
 check de l'acces a la variable TERM, recup la configuration du terminal, la sauvegarde pour le reset a la fin, et change le terminal en mode canonique + set le read de buffer pour pouvoir interpreter les caracteres "ESC [ A" (== fleche du haut) et application de ces changements (TCSANOW);;
 */

void			init_configuration(t_select *infos)
{
	if (!(infos->term_type = getenv("TERM")))
		errors_and_exit(TERM);
	get_config(infos->term_type);
	tcgetattr(2, (&infos->old_config));
	tcgetattr(2, (&infos->our_config));
	infos->our_config.c_lflag &= ~(ICANON);
	infos->our_config.c_lflag &= ~(ECHO);
	infos->our_config.c_cc[VMIN] = 1;
	infos->our_config.c_cc[VTIME] = 0;
	tcsetattr(2, TCSANOW, &(infos->our_config));
}

/*
 * initialise les signaux qu'on doit gerer avec la fonction signal_handler
 */

void			init_sig_handler()
{
	signal(SIGWINCH, sig_handler);//	    	SIGWINCH discard signal    		Window size change
	signal(SIGABRT, sig_handler); // 		SIGABRT create core image		abort program
	signal(SIGINT, sig_handler);  //  	    SIGINT terminate process   		interrupt program
	signal(SIGSTOP, sig_handler); // 		SIGSTOP stop process      stop (cannot be caught or ignored)
	signal(SIGCONT, sig_handler); // 		SIGCONT discard signal      continue after stop
	signal(SIGTSTP, sig_handler); // 		SIGTSTP stop process      stop signal generated from keyboard
	signal(SIGKILL, sig_handler); // 		SIGKILL terminate process    kill program
	signal(SIGQUIT, sig_handler); // 		SIGQUIT create core image    quit program
}