/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:59:35 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/19 15:17:59 by aschoenh         ###   ########.fr       */
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

char			*ft_pathjoin(char *cwd, char *name)
{
	char		*tmp;

	if (!cwd || !name)
		return (NULL);
	if (cwd[ft_strlen(cwd) - 1] == '/')
	{
		if (name[0] == '/')
			return (ft_strjoin(cwd, name + 1));
		else
			return (ft_strjoin(cwd, name));
	}
	else
	{
		if (name[0] == '/')
			return (ft_strjoin(cwd, name));
		else
		{
			tmp = ft_strjoin(cwd, "/");
			return (ft_strjoin(tmp, name));
		}
	}
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
