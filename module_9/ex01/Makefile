FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = RPN

all: $(NAME)

OBJECTS = main.o \
		  RPN.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ -g ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf RPN
re: fclean all

.Phony: all clean fclean re
