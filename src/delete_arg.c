/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:26:27 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/21 16:38:48 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static int			ft_delete(const char *file, const struct stat *ptr
						, int flag, struct FTW *s_ftw)
{
	int				rm;

	(void)ptr;
	(void)flag;
	(void)s_ftw;
	rm = remove(file);
	return (rm);
}

static void			delete_arg_real(char *file)
{
	struct stat		to_del;

	if (lstat(file, &to_del) == -1)
	{
		ft_putendl_fd("You tried to delete a inexistant file.", 2);
		return ;
	}
	if (S_ISDIR(to_del.st_mode))
		nftw(file, ft_delete, 64, FTW_DEPTH | FTW_PHYS);
	else
		remove(file);
}

void				delete_selected_arg(void)
{
	t_arg			*to_del;

	if (!g_infos.active_arg)
		return ;
	to_del = *g_infos.active_arg;
	if (g_infos.args == to_del)
		g_infos.args = (to_del->next == to_del) ? NULL : to_del->next;
	else
		g_infos.active_arg = &to_del->next;
	to_del->next->prev = to_del->prev;
	to_del->prev->next = to_del->next;
	delete_arg_real(to_del->value);
	g_infos.ac--;
	free(to_del->value);
	to_del->value = NULL;
	free(to_del);
	to_del = NULL;
	if (g_infos.ac == 0)
		handler(STOP);
}
