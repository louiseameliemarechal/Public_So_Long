# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 10:40:23 by lmarecha          #+#    #+#              #
#    Updated: 2021/12/17 13:58:15 by lmarecha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#INCLUDES = ft_printf.h

NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_hexa.c

OBJ = $(SRC:.c=.o)

CC = clang

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

re: fclean all
