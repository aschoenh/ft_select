/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:30:41 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/19 13:02:47 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void		errors_and_exit(int error)
{
	//free au cas ou 
	//
	if (error == USAGE)
	{
		ft_putendl_fd("ft_select need at least one argument.", 2);
		ft_putendl_fd("Usage : ./ft_select argument1, ...", 2);
	}
	if (error == TERM)
		ft_putendl_fd("TERM must be set (see \'env\').", 2);
	if (error == TERMIN)
		ft_putendl_fd("The open file descriptor is NOT reffering to a terminal", 2);
	if (error == NO_ENTRY)
		ft_putendl_fd("No entry of your terminal in the database.", 2);
	if (error == NOT_FOUND)
		ft_putendl_fd("Terminfo database could not be found.", 2);
	exit (EXIT_FAILURE);
}
