# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 17:18:55 by mhernang          #+#    #+#              #
#    Updated: 2023/03/21 14:50:14 by mhernang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs

CC = gcc

NAME = libftprintf.a

SRC = src/ft_printf.c \
		src/tools/ret_putchar.c \
		src/tools/ret_putnbr.c \
		src/tools/ret_putstr.c \
		src/tools/ret_puthex.c \
		src/tools/ret_putvoid.c \
		src/tools/ft_strlen.c \
		src/tools/ret_putuns.c \
		src/tools/ft_itoa.c

OBJ = ${SRC:.c=.o}

FLAGS = -Wall -Werror -Wextra

INCLUDE = ft_printf.h

all:	${NAME}

${NAME}: ${OBJ} ${INCLUDE}
	${LIB} ${NAME} ${OBJ}

%.o: %.c
	${CC} ${CCFLAGS} -c -o $@ $<

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclear
