FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = violence

all: $(NAME)

OBJECTS = main.o \
		Weapon.o \
		HumanA.o \
		HumanB.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf violence
re: fclean all

.Phony: all clean fclean re
