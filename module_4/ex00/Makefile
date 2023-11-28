FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = animal

all: $(NAME)

OBJECTS = main.o \
		Animal.o \
		Cat.o \
		Dog.o \
		WrongAnimal.o \
		WrongCat.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf animal
re: fclean all

.Phony: all clean fclean re
