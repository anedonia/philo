# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 15:52:38 by ldevy             #+#    #+#              #
#    Updated: 2022/08/19 19:36:15 by ldevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(addprefix srcs/, main.c utils/utils_one.c)

OBJDIR = obj

OBJS = $(addprefix ${OBJDIR}/, ${SRC:.c=.o})

NAME 	= philo

RM		= rm -rf

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g3

LIBS = -lpthread

bonus: all

all:		${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIBS}

${OBJDIR}/%.o:%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -c $< -o $@
			
clean:
	${RM} ${OBJDIR}

fclean:		clean
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus