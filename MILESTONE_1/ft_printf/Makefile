NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = ft_printf.o ft_printf_utils.o 

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re