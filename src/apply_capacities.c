/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_capacities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:44:07 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/21 18:21:03 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static t_move			get_move(unsigned int c)
{
	if (c == UP_KEY)
		return (UP_MOVE);
	else if (c == DOWN_KEY)
		return (DOWN_MOVE);
	else if (c == LEFT_KEY)
		return (LEFT_MOVE);
	else if (c == RIGHT_KEY)
		return (RIGHT_MOVE);
	else
		return (DEFAULT_MOVE);
}

/*
 * selectionne / deselectionne le fichier selectionne et place le selected sur le next
 */

static void				space_key(void)
{
	(*g_infos.active_arg)->is_selected = !(*g_infos.active_arg)->is_selected;
	g_infos.selected_nbr += (*g_infos.active_arg)->is_selected ? 1 : -1;
	if ((*g_infos.active_arg)->is_selected)
		(g_infos.active_arg) = &(*g_infos.active_arg)->next;
}

static char				*ft_get_parent_path(char *cwd)
{
	char				*last_part;
	char				*parent;

	last_part = ft_strrchr(cwd, '/');
	if (!(parent = ft_strndup(cwd, last_part - cwd)))
		errors_and_exit(MALL_ERR);
	return (parent);
}

static void				browsing(int move)
{
	DIR					*dir;
	struct dirent		*entry;
	char				*name;
	char				*cwd;

	cwd = getcwd(NULL, MAXPATHLEN);
	name = (move == BROWSE_IN) ? ft_pathjoin(cwd, (*g_infos.active_arg)->value)
		: ft_get_parent_path(cwd);
	free(cwd);
	if (!(dir = opendir(name)))
		return (free(name));
	free_all();
	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] == '.')
			continue ;
		insert_arg(entry->d_name);
	}
	closedir(dir);
	chdir(name);
	free(name);
	name = NULL;
}

/*
 * read l'input et agit sur la liste en consequence.
 * enter termine le prgm
 * space selectionne/deselectionne le choix
 * delete ou backspace delete l'argument selectionne
 * escape stop le prgm
 * move = fleches
 */

void					apply_caps(void)
{
	unsigned int		c;
/*	FILE				*fp;

	fp = fopen("/Users/aschoenh/Desktop/ft_select_git2/comment.txt", "w");
	fprintf(fp, "we got here");
	fclose(fp);
*/	while (1)
	{
	ft_putendl_fd("TOOTOTOT", 2);
		change_display();
		c = 0;
		read (2, &c, 8);
		if (c == ENTER_KEY)
			break ;
		else if (c == SPACE_KEY)
			space_key();
		else if (c == DEL_KEY || c == BCKSP_KEY)
			delete_selected_arg();
		else if (c == ESC_KEY)
			handler(STOP);
		else if (c == BROWSE_IN || c == BROWSE_OUT)
			browsing(c);
		else if (c == UP_KEY || c == DOWN_KEY || c == RIGHT_KEY
				|| c == LEFT_KEY)
			ft_move(get_move(c));
		else
			ft_dynamic_search(c);
	}
}
