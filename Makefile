# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/26 21:56:50 by julee             #+#    #+#              #
#    Updated: 2019/02/22 13:58:58 by julee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = @gcc -Wall -Werror -Wextra

SRC = main.c hook.c draw.c recog_map.c

OBJ = $(SRC:.c=.o)

LIB = ./libft/libft.a

MINLIBX = ./minilibx_macos/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(MINLIBX) -framework OpenGL -framework Appkit

$(LIB):
	@cd libft && make

clean:
	@rm -f $(OBJ)
	@cd libft && make fclean

fclean: clean
	@rm -rf $(NAME)
	@cd libft && make fclean

re: fclean all
