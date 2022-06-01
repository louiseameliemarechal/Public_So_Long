# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louisea <louisea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:41:13 by louisea           #+#    #+#              #
#    Updated: 2022/04/07 16:44:31 by lmarecha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c implement_graphic_map.c so_long_utils.c implement_game.c

CC = clang

CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address

OBJ = $(SRC:.c=.o)

MLX = ~/minilibx/libmlx_Linux.a -lXext -lX11 -I ~/minilibx/include/ #remove for MAC

LIBFT = Libft

LIBFTA = Libft/libft.a

PRINTF = Printf

PRINTFA = Printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	make -C $(PRINTF)
	# $(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFTA) $(PRINTFA)
	$(CC) $(OBJ) $(MLX) -o $(NAME) $(LIBFTA) $(PRINTFA)
	# $(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFTA) --- MAC
	#-framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C $(LIBFT)
	make clean -C $(PRINTF)
	/bin/rm -f *.o

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(PRINTF)
	/bin/rm -f $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I ~/minilibx/include/

re: fclean all

.PHONY: all clean fclean re
