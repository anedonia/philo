# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 15:52:38 by ldevy             #+#    #+#              #
#    Updated: 2022/09/26 19:34:42 by ldevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(addprefix srcs/, main.c \
					routine/routine_one.c routine/routine_two.c routine/routine_three.c\
					utils/utils_one.c \
					inits/init_one.c inits/init_two.c inits/mem_management.c)

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