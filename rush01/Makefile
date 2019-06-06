# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzomber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/13 14:04:51 by vzomber           #+#    #+#              #
#    Updated: 2019/04/14 19:12:38 by vzomber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRC = main.cpp firstModule.cpp gkrellm.cpp secondModule.cpp

OBJ = $(SRC:.cpp=.o)

INC = 

ERRFL = -Wall -Wextra -Werror 
#-fsanitize=address

FL = -lncurses

all: $(NAME)

$(OBJ): %.o: %.cpp
	@echo "\033[93mCompiling \033[0m$<"
	@clang++ $(ERRFL) -c -o $@ $< $(INC)

$(NAME): $(OBJ)
	@echo "\033[93mCompiling $(NAME)\033[0m"
	@clang++ $(ERRFL) $(FL) -o $@ $(OBJ)
	@echo "\033[92mDONE\033[0m"
	

clean:
	@echo "\033[91mDeleting $(NAME) objects\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[91mDeleting $(NAME)\033[0m"
	@rm -f $(NAME)

re: fclean all

