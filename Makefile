NAME = libft.a
COMPILE_FLAGS =	-Wall -Wextra -Werror
SRC_C = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c ft_strncmp.c


all: 	$(NAME)

$(NAME): 
	gcc $(COMPILE_FLAGS) -c $(SRC_C)
	ar -cq $(NAME) *.o

re: fclean all

fclean: clean
	rm -f $(NAME)
	

clean:
	rm -f *.o
	