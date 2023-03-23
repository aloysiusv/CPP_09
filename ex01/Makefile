# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 01:40:42 by lrandria          #+#    #+#              #
#    Updated: 2023/03/23 01:40:59 by lrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	RPN

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -Iincl -g3 -MMD -MP -std=c++98

SRC		+=	RPN.cpp
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