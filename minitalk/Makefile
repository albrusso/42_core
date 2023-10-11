# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albrusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 12:46:46 by albrusso          #+#    #+#              #
#    Updated: 2023/06/20 15:54:42 by albrusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#COL
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#VAR
SNAME = server
CNAME = client
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

#CMD
all: $(SNAME) $(CNAME)
	
	
$(SNAME): $(OBJ_SERVER)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o server
	@echo "${GREEN}Compilation of server is success${DEF_COLOR}"
$(CNAME): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o client
	@echo "${GREEN}Compilation of client is success${DEF_COLOR}"
clean:
	@make clean -C libft
	rm -rf $(OBJ_SERVER)
	rm -rf $(OBJ_CLIENT)
	@echo "${YELLOW}All objects files of minitalk have been deleted${DEF_COLOR}"
fclean: clean
	@make fclean -C libft
	@rm -f client server
	@echo "${YELLOW} Cleaning of minitalk has been done${DEF_COLOR}"
re: fclean all
.PHONY: all clean fclean re
.SILENT:
