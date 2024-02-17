FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = btc

all: $(NAME)

OBJECTS = main.o \
		  BitcoinExchange.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ -g ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf btc
re: fclean all

.Phony: all clean fclean re
