FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = zombie

all: $(NAME)

OBJECTS = main.o randomChump.o newZombie.o Zombie.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf zombie
re: fclean all

.Phony: all clean fclean re
