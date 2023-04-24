# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 12:46:45 by vagrant           #+#    #+#              #
#    Updated: 2023/03/28 19:10:48 by lrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PmergeMe

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -Iincl -g3 -MMD -MP -std=c++98

SRC		+=  PmergeMe.cpp
SRC		+=  parsing.cpp
SRC		+=	main.cpp

OBJ		:=	$(addprefix ./obj/,$(SRC:%.cpp=%.o))

DEP		=	$(OBJ:%.o=%.d)

RM		=	rm -f

all: $(NAME)

-include $(DEP)

./obj/%.o: ./srcs/%.cpp
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -rf obj/

fclean:
	rm -rf obj/
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re