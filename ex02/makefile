# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxime <maxime@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 18:52:45 by maxime            #+#    #+#              #
#    Updated: 2024/02/19 13:06:51 by maxime           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CC = c++

SRC =	./srcs/main.cpp \
		./srcs/PmergeMe.cpp \

OBJ = ${SRC:.cpp=.o}

INC = ./includes

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
	${CC} ${CPPFLAGS} -I${INC} -c $< -o ${<:.cpp=.o}

all:	${NAME}


${NAME}:	${OBJ}

	@${CC} ${CPPFLAGS} -I${INC} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME} ${DEPS}

re: fclean all

.PHONY: all clean fclean re bonus