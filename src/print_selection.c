/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:52:04 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/21 21:37:54 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			print_selection(void)
{
	t_arg		*curr;
	t_arg		*first;
	int			i;

	i = 0;
	curr = g_infos.args;
	first = curr;
	while (curr)
	{
		if (curr->is_selected)
		{
			print_value_fd(curr, 1);
			i++;
			if (i < g_infos.selected_nbr)
				ft_putstr_fd(" ", 1);
		}
		if (curr->next == first)
			break;
		curr = curr->next;
	}
}
