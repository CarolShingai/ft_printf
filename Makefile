# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 15:13:33 by cshingai          #+#    #+#              #
#    Updated: 2024/01/08 20:20:37 by cshingai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
FLAGS	= -Wall -Wextra -Werror -c
INCLUDE	= include

SRC		= ${wildcard *.c}
OBJ		= ${SRC:%.c=obj/%.o}
# SRC_BONUS	= ${addprefix src_bonus/, \
# 				ft_printf_bonus.c \
# 				print_char_bonus.c \
# 				print_hex_nbr_bonus.c \
# 				print_nbr_bonus.c \
# 				print_str_bonus.c \
# 				print_unsig_nbr_bonus.c \
# 				print_pointer_bonus.c \
# 			}
# OBJ_BONUS	= ${SRC_BONUS:src_bonus/%.c=obj/%.o}

all: ${NAME}
${NAME}: ${OBJ}
bonus: fclean ${OBJ_BONUS}

obj/%.o: %.c
	$(shell if [ ! -d obj ]; then mkdir -p obj; fi)
	${CC} ${FLAGS} -I ${INCLUDE} $< -o $@
	ar rcs ${NAME} $@

obj/%.o: src_bonus/%.c
	$(shell if [ ! -d obj ]; then mkdir -p obj; fi)
	${CC} ${FLAGS} -I ${INCLUDE} $< -o $@
	ar rcs ${NAME} $@

clean:
	rm -rf obj

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus