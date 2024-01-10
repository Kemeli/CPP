FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = bureaucrat

all: $(NAME)

OBJECTS = main.o \
		  Bureaucrat.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf bureaucrat
re: fclean all

.Phony: all clean fclean re
