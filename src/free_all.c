/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:46:11 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/21 21:09:48 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			free_all(void)
{
	t_arg		*curr;
	t_arg		*first;

	first = g_infos.args;
	while (g_infos.args)
	{
		g_infos.ac--;
		curr = g_infos.args;
		free(g_infos.args->value);
		g_infos.args->value = NULL;
		if (g_infos.args->next == first)
			break ;
		g_infos.args = g_infos.args->next;
		free(curr);
		curr = NULL;
	}
	if (curr)
	{
		free(curr);
		curr = NULL;
	}
	g_infos.args = NULL;
}
