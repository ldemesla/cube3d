# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 12:12:40 by ldemesla          #+#    #+#              #
#    Updated: 2019/12/09 18:29:03 by ldemesla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re, clean, fclean, all, bonus

NAME= cub3D

SRC_FILE=	srcs/arg_parser.c\
			srcs/arg_parser2.c\
			srcs/arg_parser3.c\
			srcs/draw.c\
			srcs/draw2.c\
			srcs/draw3.c\
			srcs/game.c\
			srcs/get_next_line.c\
			srcs/get_next_line_utils.c\
			srcs/move.c\
			srcs/move2.c\
			srcs/ray_casting.c\
			srcs/ray_casting2.c\
			srcs/utils.c\
			srcs/utils2.c\
			srcs/utils3.c\
			srcs/ft_strlen.c\
			srcs/ft_strncmp.c\
			srcs/utils4.c \
			srcs/bmp.c \

OBJ=${SRC_FILE:.c=.o}

INCLUDES= minilibx

all: $(NAME) 

$(NAME): ${OBJ}
	@gcc -Lminilibx -lmlx -framework OpenGL -framework AppKit -o cub3D ${OBJ} 

%.o: %.c
	@gcc -c -Wall -Werror -Wextra -c $< -o $@

clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all
