# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albrusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 14:16:03 by albrusso          #+#    #+#              #
#    Updated: 2023/06/20 15:55:33 by albrusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c\
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c\
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstnew.c\
		ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memset.c\
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c\
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c\
		ft_toupper.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

%.o:%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@echo "${GREEN}Compilation of libft is success${DEF_COLOR}"
clean:
	@rm -f $(OBJ)
	@echo "${YELLOW}All objects files of libft have been deleted ${DEF_COLOR}"
fclean: clean
	@rm -f $(NAME)
	@echo "${YELLOW}Cleaning of libft has been done${DEF_COLOR}"
re: fclean all
.PHONY: all clean fclean
