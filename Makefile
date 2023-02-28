# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 17:18:55 by mhernang          #+#    #+#              #
#    Updated: 2023/02/28 17:27:57 by mhernang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDE = include
LIBFT = libft
SRC = src/ft_printf.c
CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo "ft_printf compiled!"	

%.o: %.c
	${CC} ${CCFLAGS} -c -o $@ $<

clean:
	rm -f ${OBJ} ${B_OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclear
