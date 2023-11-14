FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = fragtrap

all: $(NAME)

OBJECTS = main.o \
		ClapTrap.o \
		ScavTrap.o \
		FragTrap.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf fragtrap
re: fclean all

.Phony: all clean fclean re
