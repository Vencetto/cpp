NAME =phone_book

SRC_DIR = ./cpp/
OBJ_DIR = ./obj/
INC_DIR = ./hpp/

RED = \033[31m
GREEN = \033[32m
BLUE = \033[34m
CYAN = \033[36m
MAGENTA = \033[35m
INN = \033[40;38;5;82m
IAYNN = \033[30;48;5;82m 
END = \033[0m

SRC = ClassPhoneBook.cpp main.cpp ClassContact.cpp

FLAGS = -Wall -Wextra -Werror

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all: $(NAME)

$(OBJ_DIR):
	mkdir obj

$(NAME): $(OBJ_DIR) $(OBJ)
	@clang++ $(OBJ) -o $(NAME) -I $(INC_DIR) 
	@echo "$(IAYNN)$(NAME) $(INN) ready$(END)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@clang++ -o $@ -c $< $(FLAGS) -I $(INC_DIR) 

clean: 
	@echo "$(RED)object files removed$(END)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)executable removed$(END)"
	@rm -f $(NAME)

re: fclean all
