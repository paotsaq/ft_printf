# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apinto <apinto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 04:45:48 by apinto            #+#    #+#              #
#    Updated: 2021/03/24 04:47:13 by apinto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
HEADER	= ft_printf.h
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
AR = ar -rcsv

SRCS = srcs/*.c

SRCS_BONUS =

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)


%.o: %.c
	gcc $(CFLAGS) -include $(HEADER) -c $< -o $@

clean:
	make clean -C ./libft
	rm -rf ft_*.o

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
