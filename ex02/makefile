
NAME = PmergeMe

CC = c++

SRC =	main.cpp \
		PmergeMe.cpp \

OBJ = ${SRC:.cpp=.o}

INC = ./includes

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

.cpp.o:
	${CC} ${CPPFLAGS} -I${INC} -c $< -o ${<:.cpp=.o}

all:	${NAME}


${NAME}:	${OBJ}

	@${CC} ${CPPFLAGS} -I${INC} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
