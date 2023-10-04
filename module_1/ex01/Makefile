FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = phonebook

all: $(NAME)

OBJECTS = main.o phonebook.o contact.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf phonebook
re: fclean all
