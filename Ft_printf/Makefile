# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 23:16:28 by bcarpent          #+#    #+#              #
#    Updated: 2024/01/12 04:12:41 by bcarpent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS =	ft_printf.c ft_utils_printf.c ft_putnbrptr_printf.c \
	ft_putnbrhexa_printf.c ft_itoa.c ft_uitoa.c

OBJS = ${SRCS:.c=.o}

DEPS = ${OBJS:.o=.d}

all : ${NAME}
-include ${DEPS}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o : %.c
	${CC} ${FLAGS} -o $@ -c $<

clean :
	rm -f ${OBJS} ${DEPS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
