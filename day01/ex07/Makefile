NAME = replace

SRC = main.cpp

OBJ = main.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@clang++ $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) is ready"

%.o: %.cpp 
	@clang++ -c $< -o $@ $(FLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
