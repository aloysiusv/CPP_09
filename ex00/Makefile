# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 12:13:24 by lrandria          #+#    #+#              #
#    Updated: 2023/04/30 18:28:23 by lrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	btc

CXX		=	c++

CXXFLAGS =	-Wall -Wextra -Werror -Iincl -g3 -MMD -MP -std=c++98

SRCS		=	BitcoinExchange.cpp \
			main.cpp \
			errors.cpp

OBJS		:=	$(addprefix ./obj/,$(SRCS:%.cpp=%.o))

DEP		=	$(OBJS:%.o=%.d)

RM		=	rm -f

all: $(NAME)

-include $(DEP)

./obj/%.o: ./srcs/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

clean:
	rm -rf obj/

fclean:
	rm -rf obj/
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re