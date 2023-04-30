# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 12:46:45 by vagrant           #+#    #+#              #
#    Updated: 2023/04/30 18:40:52 by lrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PmergeMe

CXX		=	c++

CXXFLAGS =	-Wall -Wextra -Werror -Iincl -g3 -MMD -MP -std=c++98

SRCS	= 	PmergeMe.cpp \
			parsing.cpp \
			main.cpp

OBJS		:=	$(addprefix ./objs/,$(SRCS:%.cpp=%.o))

DEP		=	$(OBJS:%.o=%.d)

RM		=	rm -f

all: $(NAME)

-include $(DEP)

./objs/%.o: ./srcs/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

clean:
	rm -rf objs/

fclean:
	rm -rf objs/
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re