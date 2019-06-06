NAME = ft_retro

SRC_DIR = ./src/
OBJ_DIR = ./obj/

RED = \033[31m
GREEN = \033[32m
BLUE = \033[34m
CYAN = \033[36m
MAGENTA = \033[35m
INN = \033[40;38;5;82m
IAYNN = \033[30;48;5;82m 
END = \033[0m

SRC = 	main.cpp\
      	Game.Class.cpp\
      	Map.Class.cpp\
      	Handler.Class.cpp\
      	Player.cpp\
      	Point.cpp\
      	Bullet.cpp\
      	Metheorite.cpp\
      	Enemy.cpp\
      	Objects.cpp

HEADER = Map.Class.hpp Game.Class.hpp

FLAGS = -Wall -Wextra -Werror 

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir obj

$(NAME): $(OBJ_DIR) $(OBJ)
	@clang++  -l ncurses $(OBJ) -o $(NAME) -I inc/ 
	@echo "$(IAYNN)$(NAME) $(INN) ready $(END)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@clang++ -o $@ -c $< $(FLAGS) -I inc/

clean: 
	@echo "$(RED)object files removed$(END)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)executable removed$(END)"
	@rm -f $(NAME)

re: fclean all
