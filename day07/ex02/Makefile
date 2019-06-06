# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzomber  <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/16 16:42:45 by vzomber           #+#    #+#              #
#    Updated: 2019/04/11 15:59:14 by vzomber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

INC = -I inc/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ): %.o: %.cpp
	@echo "\033[93mCompiling \033[0m$<"
	@clang++ $(FLAGS) -c -o $@ $< $(INC)

$(NAME): $(OBJ)
	@echo "\033[93mCompiling $(NAME)\033[0m"
	@clang++ $(FLAGS) $(FL) -o $@ $(OBJ)
	@echo "\033[92mDONE\033[0m"
	

clean:
	@echo "\033[91mDeleting $(NAME) objects\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[91mDeleting $(NAME)\033[0m"
	@rm -f $(NAME)

re: fclean all
