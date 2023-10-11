# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albrusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 16:21:18 by albrusso          #+#    #+#              #
#    Updated: 2023/04/19 14:36:14 by albrusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variable

SRC_DIR_MANDATORY	= srcs/
SRC_DIR_BONUS = bonus/
SRC_DIR_GET_NEXT_LINE = bonus/get_next_line/
CFLAGS	= -Wall -Wextra -Werror -g
NAME_MANDATORY	= push_swap


# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


SRC_MANDATORY	=	function_evaluate.c function_evaluate_two.c function_for_order.c \
				function_lst_one.c function_lst_two.c function_utils.c function_utils_two.c \
				main.c rules_push.c rules_swap.c rules_reverse_rotate.c rules_rotate.c \
				table.c table_two.c table_three.c split.c new_argc.c split_two.c

SRC_BONUS_ONE	=	function_evaluate.c function_evaluate_two.c function_for_order.c \
				function_lst_one.c function_lst_two.c function_utils.c function_utils_two.c \
				rules_push.c rules_swap.c rules_reverse_rotate.c rules_rotate.c \
				table.c table_two.c table_three.c split.c split_two.c new_argc.c

SRC_BONUS_TWO	=	bonus.c function_to_execute_rules.c

SRC_BONUS_THREE	=	get_next_line.c get_next_line_utils.c


SRCS_BONUS_ONE	= $(addprefix $(SRC_DIR_MANDATORY), $(SRC_BONUS_ONE))

SRCS_BONUS_TWO	= $(addprefix $(SRC_DIR_BONUS), $(SRC_BONUS_TWO))

SRCS_BONUS_THREE	= $(addprefix $(SRC_DIR_GET_NEXT_LINE), $(SRC_BONUS_THREE))

SRCS_MANDATORY	= $(addprefix $(SRC_DIR_MANDATORY), $(SRC_MANDATORY))
OBJ_MANDATORY	= $(SRCS_MANDATORY:.c=.o)

OBJ_BONUS		= $(SRCS_BONUS_ONE:.c=.o) $(SRCS_BONUS_TWO:.c=.o) $(SRCS_BONUS_THREE:.c=.o)


all: $(NAME_MANDATORY)

$(NAME_MANDATORY): $(OBJ_MANDATORY)
		  	cc $(CFLAGS) $(OBJ_MANDATORY) -o $(NAME_MANDATORY)
			@echo "$(GREEN) push_swap compiled!$(DEF_COLOR)"

bonus: $(OBJ_BONUS)
			cc $(CFLAGS) $(OBJ_BONUS) -o checker
			@echo "$(GREEN) checker compiled!$(DEF_COLOR)"

clean:
		rm -f $(OBJ_MANDATORY) $(OBJ_BONUS)
		@echo "$(BLUE)push_swap object files cleaned!$(DEF_COLOR)"
		@echo "$(BLUE)checker object files cleaned!$(DEF_COLOR)"

fclean:	clean
		rm -f $(NAME_MANDATORY) checker
		@echo "$(CYAN)push_swap executable files cleaned!$(DEF_COLOR)"
		@echo "$(CYAN)checker executable files cleaned!$(DEF_COLOR)"
re:	fclean all bonus

PHONY:		all clean fclean re

.SILENT:
