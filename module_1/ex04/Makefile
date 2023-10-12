FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = out

all: $(NAME)

OBJECTS = main.o \
		FileManipulation.o


$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf out
re: fclean all

.Phony: all clean fclean re
