NAME = megaphone

SRC = megaphone.cpp

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	clang++ -o $@ -c $< $(FLAGS) 

$(NAME): $(OBJ)
	clang++ $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
