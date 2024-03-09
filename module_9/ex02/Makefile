FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = PmergeMe

all: $(NAME)

OBJECTS = main.o \
		  PmergeMe.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ -g ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf PmergeMe
re: fclean all

.Phony: all clean fclean re
