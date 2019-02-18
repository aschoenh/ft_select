/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:20:20 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/18 20:19:47 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"


int				main(int ac, char **av)
{
	if (ac < 2)
		errors_and_exit(USAGE);
	init_args(av + 1);
	init_configuration();
	init_sig_handler();
	apply_caps();
	reset_config();
//	print_selection();
//	free_all();
	return (0);
}
