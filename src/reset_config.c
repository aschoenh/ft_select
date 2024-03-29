/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:06:02 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/19 13:24:18 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void		reset_config(void)
{
	tcsetattr(2, TCSANOW, &(g_infos.old_config));	
	tputs(tgetstr("te", NULL), 1, ft_print_puts);
	tputs(tgetstr("ve", NULL), 1, ft_print_puts);
}
