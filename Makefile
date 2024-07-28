SRS = ft_alloc.c

OBJS = $(SRS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = ft_alloc.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re