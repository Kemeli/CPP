FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = harl

all: $(NAME)

OBJECTS = Harl.o \
		main.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf harl
re: fclean all

.Phony: all clean fclean re
