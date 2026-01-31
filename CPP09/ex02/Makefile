CC = c++
NAME = PmergeMe
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp PmergeMe.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re