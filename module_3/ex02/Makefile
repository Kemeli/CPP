FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = fixed

all: $(NAME)

OBJECTS = main.o \
		  Fixed.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf fixed
re: fclean all

.Phony: all clean fclean re
