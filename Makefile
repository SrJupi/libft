NAME := libft.a
COMPILE_FLAGS =	-Wall -Wextra -Werror


all: 	$(NAME)

$(NAME): 
	gcc $(COMPILE_FLAGS) -c $(wildcard *.c)
	ar -cvq $(NAME) *.o

re: fclean all

fclean: clean
	rm -f $(NAME)
	

clean:
	rm -f *.o
	