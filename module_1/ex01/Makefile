FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = phonebook

all: $(NAME)

OBJECTS = main.o PhoneBook.o Contact.o

$(NAME): $(OBJECTS)
	c++ $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	c++ ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf phonebook
re: fclean all

.Phony: all clean fclean re
