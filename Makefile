#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apinto <apinto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 04:45:48 by apinto            #+#    #+#              #
#    Updated: 2021/03/24 12:45:23 by apinto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
HDRS		= includes
CFLAGS 		= -Wall -Wextra -Werror
AR 			= ar -rcsv
NAME 		= libftprintf.a
SRCS		= $(wildcard ./srcs/*.c)
OBJS 		= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): libft.a $(OBJS)
	$(AR) $(NAME) $(OBJS)

libft.a: 
	$(MAKE) libft.a -C ./libft
	

%.o: %.c 
	gcc $(CFLAGS) -I $(HDRS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -rf ft_*.o

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
