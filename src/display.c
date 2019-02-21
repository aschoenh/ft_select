/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:35:05 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/21 18:09:54 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static int			get_terminal_size(t_dim dim)
{
	struct winsize	s;

	ioctl(2, TIOCGWINSZ, &s);
	return (dim == W ? s.ws_col : s.ws_row);
}

int					get_columns(void)
{
	int				cols;

	cols = get_terminal_size(W) / (get_max_len_args() + 1);
	if (!cols)
		cols = 1;
	if ((get_max_len_args() + 1) * g_infos.ac < get_terminal_size(W))
		cols = g_infos.ac;
	return (cols);
}

void				print_value_fd(t_arg *arg, int fd)
{
	if (fd == 2)
	{
		if (arg->type == C_TYPE)
			ft_putstr_fd(C_COLOR, 2);
		else if (arg->type == O_TYPE)
			ft_putstr_fd(O_COLOR, 2);
		else if (arg->type == H_TYPE)
			ft_putstr_fd(H_COLOR, 2);
		else if (arg->type == MAKEFILE_TYPE)
			ft_putstr_fd(MAKEFILE_COLOR, 2);
		else if (arg->type == DOT_TYPE)
			ft_putstr_fd(DOT_COLOR, 2);
		else if (arg->type == A_TYPE)
			ft_putstr_fd(AA_COLOR, 2);
	}
	ft_putstr_fd(arg->value, fd);
	if (fd == 2)
		ft_putstr_fd(DEFAULT_COLOR, 2);
}

static void			display_args(t_arg *args, t_arg *first, int rows, int cols)
{
	int				i;
	int				j;
	int				len;

	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			if (args == (*g_infos.active_arg))
				ft_putstr_fd(UNDERLINED, 2);
			if (args->is_selected)
				ft_putstr_fd(REV_VID_COLOR, 2);
			print_value_fd(args, 2);
			len = ft_strlen(args->value);
			while (len++ <= get_max_len_args())
				ft_putstr_fd(" ", 2);
			if (args->next == first)
				break ;
			args = args->next;
		}
		ft_putstr_fd("\n", 2);
	}
}

void				change_display(void)
{
	int				cols;
	int				rows;

	if (!g_infos.args || get_max_len_args() > get_terminal_size(W))
		return ;
	tputs(tgetstr("cl", NULL), 1, ft_print_puts);
	cols = get_columns();
	rows = get_rows(cols);
	if (rows > get_terminal_size(H))
		return ;
	if (g_infos.ac % cols)
		++rows;
	display_args(g_infos.args, g_infos.args, rows, cols);
}
