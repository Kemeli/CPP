FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = convert

all: $(NAME)

OBJECTS = main.o \
		  Base.o \
		  Functions.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ -g ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf convert
re: fclean all

.Phony: all clean fclean re
