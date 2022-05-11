NAME := libft.a
COMPILE_FLAGS =	-Wall -Wextra -Werror


all: 	create_obj create_lib

create_obj: 
	gcc $(COMPILE_FLAGS) -c $(wildcard *.c)

create_lib: 
	ar -cvq $(NAME) *.o

re: fclean

fclean: clean
	rm -f *.o

clean:
	rm -f a.out
	rm -f *.log
	rm -f $(NAME)