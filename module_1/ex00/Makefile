FLAGS = -std=c++98 -Wall -Wextra -Werror

all: megaphone

megaphone: megaphone.o
	c++ -g $(FLAGS) -o $@ $<
clean:
	rm -f megaphone.o
fclean: clean
	rm -rf megaphone
re: fclean all
