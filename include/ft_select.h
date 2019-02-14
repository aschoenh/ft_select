/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:13:11 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/14 19:39:37 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdlib.h>
# include <termcap.h>
# include <../libft/libft.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termios.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <term.h>
# include <curses.h>
# include <sys/param.h>


typedef	struct			s_select
{
	char				*term_type;
	struct termios		old_config;
	int					ac;
//	t_arg				*args;
	struct termios		our_config;
	int					real_mode;
//	t_arg				**selected_arg;
	int					selected_nbr;
}						t_select;

enum					{USAGE, TERM, TERMIN, NO_ENTRY, NOT_FOUND, MALL_ERR};
enum					{STOP, SUSPEND};
void					errors_and_exit(int error);
void					init_configuration(t_select *infos);
void					init_sign_handler(t_select infos);
void					reset_config(t_select infos);
void					sig_handler(int signo, t_select infos);

#endif
