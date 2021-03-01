# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 11:53:40 by antonmar          #+#    #+#              #
#    Updated: 2021/02/09 13:26:35 by antonmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SONAME = printf.so
CC = gcc
FLAGS = -Wall -Wextra -Werror -I./ -c
FILES = src/*.c

FILES_BONUS = 
OBJ = $(FILES:src/%.c=%.o)

OBJ_BONUS = $(FILES_BONUS:src/%.c=%.o)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
		gcc $(FLAGS) $(FILES)

all: $(NAME)

clean:
		rm -f $(OBJ)
		rm -f $(OBJ_BONUS)
fclean: clean
		rm -f $(NAME)
		rm -f $(SONAME)
re: fclean all

so:		
		gcc -shared -o $(SONAME) -fPIC $(FILES) $(FILES_BONUS)
bonus:	$(OBJ) $(OBJ_BONUS)
		ar rcs $(NAME) $(NAME_BONUS) $(OBJ) $(OBJ_BONUS) 

.PHONY: all clean fclean re so bonus