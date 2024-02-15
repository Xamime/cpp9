# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 13:39:07 by maxime            #+#    #+#              #
#    Updated: 2024/01/19 13:10:34 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.cpp 
		
NAME = ex02
CXX = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
OBJ = $(SRC:cpp=o)

all: $(NAME)

%.o: %.c
	${CXX} ${CPPFLAGS} -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus