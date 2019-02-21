/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:10:15 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/21 16:16:27 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static t_type		get_type(char *file)
{
	char			*name;

	if (!((name = ft_strrchr(file, '/'))))
		name = file;
	if (name[0] == '.')
		return (DOT_TYPE);
	else if (!(ft_strcmp(ft_tolower(file), "makefile")))
		return (MAKEFILE_TYPE);
	else 
		name = ft_strrev(name);
	if (name[0] == 'c' && name[1] == '.')
		return (C_TYPE);
	else if (name[0] == 'h' && name[1] == '.')
		return (H_TYPE);
	else if (name[0] == 'a' && name[1] == '.')
		return (A_TYPE);
	else if (name[0] == 'o' && name[1] == '.')
		return (O_TYPE);
	else if (name[0] == 'h' && name[1] == '.')
		return (H_TYPE);
	return (OTHER_TYPE);
}

void				insert_arg(char *file)
{
	t_arg			*new;
	t_arg			*end;

	if (!(new = (t_arg *)ft_memalloc(sizeof(t_arg))))
		errors_and_exit(MALL_ERR);
	if (!(new->value = ft_strdup(file)))
		errors_and_exit(MALL_ERR);
	new->type = get_type(file);
	g_infos.ac++;
	if (!g_infos.args)
	{
		new->prev = new;
		new->next = new;
		g_infos.args = new;
		g_infos.active_arg = &g_infos.args;
		return ;
	}
	end = g_infos.args->prev;
	new->next = g_infos.args;
	g_infos.args->prev = new;
	new->prev = end;
	end->next = new;
}

void				init_args(char **av)
{
	int				i;

	i = -1;
	g_infos.ac = 0;
	while (av[++i])
		insert_arg(av[i]);
	g_infos.selected_nbr = 0;
}
