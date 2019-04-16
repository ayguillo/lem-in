# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlambert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 14:36:18 by vlambert          #+#    #+#              #
#    Updated: 2019/04/15 11:38:44 by ayguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= lem-in
DEBUG = -g3 -fsanitize=address
FLAGS = -Wall -Wextra -Werror -g3
SRC = 	main.c parsepipe.c parsroom.c tools.c ft_error.c create_sol.c bfs.c \
		freeall.c printsol.c printline.c
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a

all: $(NAME) 

$(NAME): $(LIB) $(OBJ)
	@ echo "\033[0;33mCompilation de $(NAME)...\x1b[0m"
	@ gcc -o $(NAME) $(OBJ) $(LIB)
	@ echo "\033[0;32mLem-in compilé -> OK\x1b[0m"

%.o : %.c lemin.h
	@ gcc $(FLAGS) -c $<

$(LIB) :
	@ make -C libft

clean:
	@ rm -rf $(OBJ)
	@ make clean -C libft
	@ echo "\033[0;31mSuppression des .o \033[0;33m-> \033[0;32mOK\x1b[0m"

fclean: clean
	@ rm -f $(LIB)
	@ rm -rf $(NAME)
	@ echo "\033[0;31mSuppression de $(NAME) \033[0;33m-> \033[0;32mOK\x1b[0m"

flcean: fclean

re: fclean all

.PHONY: clean fclean re all
