FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = templates

all: $(NAME)

OBJECTS = main.o \

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ -g ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf templates
re: fclean all

.Phony: all clean fclean re
