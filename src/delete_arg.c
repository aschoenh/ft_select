/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:26:27 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/19 13:45:53 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"
/*
void				delete_arg_real(char *file)
{

}
*/
void				delete_selected_arg(void)
{
	t_arg			*to_del;

	if (!g_infos.active_arg)
		return ;
	to_del = *g_infos.active_arg;
	//
	g_infos.active_arg = &to_del->next;
	to_del->next->prev = to_del->prev;
	to_del->prev->next = to_del->next;
//	delete_arg_real(to_del->value);
	g_infos.ac--;
	free(to_del->value);
	to_del->value = NULL;
	free(to_del);
	to_del = NULL;
	if (g_infos.ac == 0)
		handler(STOP);
}
