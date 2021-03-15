SRCS	= ft_printf.c ft_handlers.c flag.c pars.c ft_utils.c

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

LIB			= libft.a

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
NC=\033[0m

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIB)
	cp libft/$(LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIB):
	make -C libft

clean:
	$(RM) $(OBJS) libft/*.o

fclean:		clean
	$(RM) libft/$(LIB) $(NAME)

re:		fclean all
