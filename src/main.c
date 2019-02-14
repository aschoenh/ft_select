/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:20:20 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/14 19:39:56 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int				main(int ac, char **av)
{
	t_select	infos;

	if (ac < 2)
		errors_and_exit(USAGE);
	init_configuration(&infos);
	init_sig_handler(infos);
//	apply_caps();
//	reset_configuration();
//	print_selection();
//	free_all();
	return (0);
}
