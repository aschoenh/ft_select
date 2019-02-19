/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:13:11 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/19 15:21:58 by aschoenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdlib.h>
# include <termcap.h>
# include <../libft/libft.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termios.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <term.h>
# include <curses.h>
# include <sys/param.h>

# define ENTER_KEY		0xA
# define SPACE_KEY		0x20
# define DEL_KEY		0x7E335B1B
# define BCKSP_KEY		0x7F
# define ESC_KEY		0x1B
# define BROWSE_IN		43
# define BROWSE_OUT		45
# define UP_KEY			0x415B1B
# define DOWN_KEY		0x425B1B
# define RIGHT_KEY		0x435B1B
# define LEFT_KEY		0x445B1B


# define C_COLOR		"\033[35m"
# define O_COLOR		"\033[36m"
# define H_COLOR		"\033[34m"
# define MAKEFILE_COLOR	"\033[33m"
# define DOT_COLOR		"\033[32m"
# define DEFAULT_COLOR	"\033[0m"
# define AA_COLOR		"\033[31m"
# define REV_VID_COLOR	"\033[7m"
# define UNDERLINED		"\033[4m"

typedef enum			e_type
{
	C_TYPE,
	A_TYPE,
	H_TYPE,
	O_TYPE,
	MAKEFILE_TYPE,
	DOT_TYPE,
	OTHER_TYPE
}						t_type;

typedef struct			s_arg
{
	char				*value;
	int					is_selected;
	t_type				type;
	struct s_arg		*next;
	struct s_arg		*prev;
}						t_arg;

typedef	struct			s_infos
{
	char				*term_type;
	struct termios		old_config;
	int					ac;
	t_arg				*args;
	struct termios		our_config;
	int					real_mode;
	t_arg				**active_arg;
	int					selected_nbr;
}						t_infos;

typedef enum			e_move
{
	UP_MOVE,
	RIGHT_MOVE,
	LEFT_MOVE,
	DOWN_MOVE,
	DEFAULT_MOVE
}						t_move;

typedef enum			e_dim
{
	H,
	W
}						t_dim;

t_infos					g_infos;

enum					{USAGE, TERM, TERMIN, NO_ENTRY, NOT_FOUND, MALL_ERR};

typedef enum			e_handle
{
	STOP,
	SUSPEND
}						t_handle;

char					*ft_pathjoin(char *cwd, char *name);
void					errors_and_exit(int error);
void					init_configuration(void);
void					init_sig_handler(void);
void					reset_config(void);
void					init_sig_handler(void);
void					sig_handler(int signo);
void					handler(t_handle action);
void					apply_caps(void);
void					init_args(char **args);
void					insert_arg(char *file);
void					ft_move(t_move direction);
void					change_display(void);
int						get_columns(void);
int						get_rows(int cols);
int						get_max_len_args(void);
int						ft_print_puts(int n);
void					print_value_fd(t_arg *arg, int fd);
void					delete_selected_arg(void);
void					free_all(void);
void					print_selection(void);

#endif
