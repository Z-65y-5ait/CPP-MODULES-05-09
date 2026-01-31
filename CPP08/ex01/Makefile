CC = c++
NAME = Span
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Span.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp Span.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re