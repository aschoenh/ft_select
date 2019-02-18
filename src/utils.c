/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:59:35 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/18 20:19:14 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int				ft_print_puts(int n)
{
	return (write(2, &n, 1));
}

int				get_rows(int cols)
{
	return (g_infos.ac / cols);
}

int				get_max_len_args(void)
{
	int			max;
	int			curr;
	t_arg		*first;
	t_arg		*tmp;

	if (!g_infos.args || !g_infos.args->value)
		return (0);
	max = 0;
	tmp = g_infos.args;
	first = tmp;
	while (tmp)
	{
		curr = ft_strlen(tmp->value);
		if (curr > max)
			max = curr;
		if (tmp->next == first)
			break ;
		tmp = tmp->next;
	}
	return (max);
}
