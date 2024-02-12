FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = containers

all: $(NAME)

OBJECTS = main.o \
		  Span.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ -g ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf containers
re: fclean all

.Phony: all clean fclean re
