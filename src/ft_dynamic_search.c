/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynamic_search.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:47:57 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/21 20:02:05 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			ft_dynamic_search(int c)
{
	static char	search[1024];
	int			i;
	t_arg		*tmp;

	tmp = *g_infos.active_arg;
	i = 0;
	while (search[i] != '\0')
		i++;
	search[i] = c;
	while (tmp)
	{
		if (!(ft_strncmp(search, tmp->value, i + 1)))
		{
			g_infos.active_arg = &tmp->prev;
			ft_move(RIGHT_MOVE);
			break;
		}
		tmp = tmp->next;
		if (tmp == *g_infos.active_arg)
		{
			ft_memset(search, 0, 1024);
			break ;
		}
	}
}
