NAME = libft.a

COMPILE_FLAGS =	-Wall -Wextra -Werror

SRC_C = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_bzero.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_strnstr.c ft_strlcat.c ft_memcpy.c ft_memmove.c ft_strdup.c ft_strlcpy.c ft_calloc.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_striteri.c ft_strmapi.c ft_split.c ft_strtrim.c

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c $(SRC_C)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ = $(SRC_C:.c=.o)

all: 	$(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

re: fclean all

fclean: clean
	rm -f $(NAME)
	

clean:
	rm -f *.o
	

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)