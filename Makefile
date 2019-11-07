# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 12:12:40 by ldemesla          #+#    #+#              #
#    Updated: 2019/11/07 14:18:55 by ldemesla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re, clean, fclean, all, bonus

NAME= cube3d

SRC_FILE=	arg_parser.c\
			arg_parser2.c\
			arg_parser3.c\
			draw.c\
			draw2.c\
			draw3.c\
			game.c\
			get_next_line.c\
			get_next_line_utils.c\
			move.c\
			move2.c\
			ray_casting.c\
			ray_casting2.c\
			utils.c\
			utils2.c\
			utils3.c\
			ft_strlen.c\
			ft_strncmp.c\
			utils4.c \

OBJ=${SRC_FILE:.c=.o}

INCLUDES= minilibx

all: $(NAME) 

$(NAME): ${OBJ}
	@gcc -Lminilibx -lmlx -framework OpenGL -framework AppKit -o cube3d ${OBJ} 

%.o: %.c
	@gcc -c -Wall -Werror -Wextra -c $< -o $@

clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all
