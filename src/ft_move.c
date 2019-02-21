/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:45:33 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/21 21:37:53 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void			ft_move_up(void)
{
	int				i;
	t_arg			*tmp;
	int				cols;

	i = 0;
	tmp = *g_infos.active_arg;
	cols = get_columns();
	while (++i < cols)
		tmp = tmp->prev;
	g_infos.active_arg = &tmp->prev;
}

static void			ft_move_down(void)
{
	int				i;
	t_arg			*tmp;
	int				cols;

	i = 0;
	tmp = *g_infos.active_arg;
	cols = get_columns();
	while (++i < cols)
		tmp = tmp->next;
	g_infos.active_arg = &tmp->next;
}
void				ft_move(t_move direction)
{
	t_arg			*active;

	active = *g_infos.active_arg;
	if (direction == UP_MOVE)
		ft_move_up();
	else if (direction == DOWN_MOVE)
		ft_move_down();
	else if (direction == LEFT_MOVE)
		g_infos.active_arg = &active->prev;
	else if (direction == RIGHT_MOVE)
		g_infos.active_arg = &active->next;
}
