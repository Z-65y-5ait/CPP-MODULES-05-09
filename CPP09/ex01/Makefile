CC = c++
NAME = RPN
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp RPN.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re