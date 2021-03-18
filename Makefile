CC = gcc
COMP = $(CC) $(OPT)
OPT = -Wall -Wextra -Werror
SRCS = *.c
SRCS_OBJS := ${SRCS:.c=.o}
LST := ft_lst*.c
LST_OBJS := ${LST:.c=.o}
HDRS = .
NAME = libft.a
RM = rm -f

all:
	$(CC) $(OPT) -I $(HDRS) -c $(SRCS)
	ar -rcs $(NAME) $(SRCS_OBJS) $(LST_OBJS)

bonus:
	$(CC) $(OPT) -I $(HDRS) -c $(LST)

$(NAME):
	all

debug:
	$(CC) $(OPT) -g -I $(HDRS) -c $(SRCS)

clean:
	$(RM) *.o

fclean: clean
		$(RM) $(NAME)

re: fclean all
