FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = claptrap

all: $(NAME)

OBJECTS = main.o \
		 ClapTrap.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf claptrap
re: fclean all

.Phony: all clean fclean re
