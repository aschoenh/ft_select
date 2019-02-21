/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:20:20 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/21 18:41:12 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int				main(int ac, char **av)
{
	int			i;

	i = 1;
	if (ac < 2)
		errors_and_exit(USAGE);
	if (av[1][0] && av[1][1] == 'R' && !av[1][2])
	{
		g_infos.no_kidding = 1;
		i++;
	}
	init_configuration();
	init_args(av + i);
	init_sig_handler();
	apply_caps();
	reset_config();
	print_selection();
	free_all();
	return (0);
}
