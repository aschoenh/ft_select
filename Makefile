# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschoenh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 15:11:11 by aschoenh          #+#    #+#              #
#    Updated: 2019/02/21 20:21:11 by aschoenh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
CC = gcc # -Wall -Wextra -Werror
CC_FLAGS = -I$(LFT_PATH)/include

LFT_PATH = ./libft/
SRC_PATH = ./src/
INC_PATH = ./include/ $(LFT_PATH)
OBJ_PATH = ./obj/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_NAME = main.c errors.c init_configuration.c reset_config.c sig_handler.c apply_capacities.c ft_move.c display.c utils.c init_args.c delete_arg.c free_all.c print_selection.c ft_dynamic_search.c

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_PATH)
	$(CC) -o $(NAME) $(OBJ) -L$(LFT_PATH) -lft -ltermcap -fsanitize=address -g3

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	make -C $(LFT_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
