/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:13:11 by aschoenh          #+#    #+#             */
/*   Updated: 2019/02/21 21:19:38 by aschoenh         ###   ########.fr       */
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
# include <ftw.h>

# define ENTER_KEY			0xA
# define SPACE_KEY			0x20
# define DEL_KEY			0x7E335B1B
# define BCKSP_KEY			0x7F
# define ESC_KEY			0x1B
# define BROWSE_IN			43
# define BROWSE_OUT			45
# define UP_KEY				0x415B1B
# define DOWN_KEY			0x425B1B
# define RIGHT_KEY			0x435B1B
# define LEFT_KEY			0x445B1B

# define KEY_CODE_LOWER_A	0x61
# define KEY_CODE_LOWER_B	0x62
# define KEY_CODE_LOWER_C	0x63
# define KEY_CODE_LOWER_D	0x64
# define KEY_CODE_LOWER_E	0x65
# define KEY_CODE_LOWER_F	0x66
# define KEY_CODE_LOWER_G	0x67
# define KEY_CODE_LOWER_H	0x68
# define KEY_CODE_LOWER_I	0x69
# define KEY_CODE_LOWER_J	0x6a
# define KEY_CODE_LOWER_K	0x6b
# define KEY_CODE_LOWER_L	0x6c
# define KEY_CODE_LOWER_M	0x6d
# define KEY_CODE_LOWER_N	0x6e
# define KEY_CODE_LOWER_O	0x6f
# define KEY_CODE_LOWER_P	0x70
# define KEY_CODE_LOWER_Q	0x71
# define KEY_CODE_LOWER_R	0x72
# define KEY_CODE_LOWER_S	0x73
# define KEY_CODE_LOWER_T	0x74
# define KEY_CODE_LOWER_U	0x75
# define KEY_CODE_LOWER_V	0x76
# define KEY_CODE_LOWER_W	0x77
# define KEY_CODE_LOWER_X	0x78
# define KEY_CODE_LOWER_Y	0x79
# define KEY_CODE_LOWER_Z	0x7a

# define KEY_CODE_UPPER_A	0x41
# define KEY_CODE_UPPER_B	0x42
# define KEY_CODE_UPPER_C	0x43
# define KEY_CODE_UPPER_D	0x44
# define KEY_CODE_UPPER_E	0x45
# define KEY_CODE_UPPER_F	0x46
# define KEY_CODE_UPPER_G	0x47
# define KEY_CODE_UPPER_H	0x48
# define KEY_CODE_UPPER_I	0x49
# define KEY_CODE_UPPER_J	0x4a
# define KEY_CODE_UPPER_K	0x4b
# define KEY_CODE_UPPER_L	0x4c
# define KEY_CODE_UPPER_M	0x4d
# define KEY_CODE_UPPER_N	0x4e
# define KEY_CODE_UPPER_O	0x4f
# define KEY_CODE_UPPER_P	0x50
# define KEY_CODE_UPPER_Q 	0x51
# define KEY_CODE_UPPER_R	0x52
# define KEY_CODE_UPPER_S	0x53
# define KEY_CODE_UPPER_T	0x54
# define KEY_CODE_UPPER_U	0x55
# define KEY_CODE_UPPER_V	0x56
# define KEY_CODE_UPPER_W	0x57
# define KEY_CODE_UPPER_X	0x58
# define KEY_CODE_UPPER_Y	0x59
# define KEY_CODE_UPPER_Z	0x5a

# define KEY_CODE_DIGIT_10	0x30
# define KEY_CODE_DIGIT_1	0x31
# define KEY_CODE_DIGIT_2	0x32
# define KEY_CODE_DIGIT_3	0x33
# define KEY_CODE_DIGIT_4	0x34
# define KEY_CODE_DIGIT_5 	0x35
# define KEY_CODE_DIGIT_6	0x36
# define KEY_CODE_DIGIT_7	0x37
# define KEY_CODE_DIGIT_8	0x38
# define KEY_CODE_DIGIT_9	0x39

# define KEY_CODE_OTHER		0x0

# define C_COLOR			"\033[35m"
# define O_COLOR			"\033[36m"
# define H_COLOR			"\033[34m"
# define MAKEFILE_COLOR		"\033[33m"
# define DOT_COLOR			"\033[32m"
# define DEFAULT_COLOR		"\033[0m"
# define AA_COLOR			"\033[31m"
# define REV_VID_COLOR		"\033[7m"
# define UNDERLINED			"\033[4m"

typedef enum				e_type
{
	C_TYPE,
	A_TYPE,
	H_TYPE,
	O_TYPE,
	MAKEFILE_TYPE,
	DOT_TYPE,
	OTHER_TYPE
}							t_type;

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
	t_arg				**active_arg;
	int					selected_nbr;
	int					no_kidding;
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

void					ft_dynamic_search(int c);
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
