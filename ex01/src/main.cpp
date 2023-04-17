/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:13:12 by estoffel          #+#    #+#             */
/*   Updated: 2023/03/24 03:02:32 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static int isop(int c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (1);
	return (0);
}

static int handle_err(std::string expr) {

	if (expr == "" || isop(expr[0])) {
		std::cerr << "Error" << std::endl;
		return -1;
	}
	for (size_t i = 0; i < expr.size(); ++i) {
		if (!isdigit(expr[i]) && !isspace(expr[i]) && !isop(expr[i])) {
				std::cerr << "Error" << std::endl;
				return -1;
		}
		if (i != 0 && ((isdigit(expr[i]) && !isspace(expr[i - 1]))
			|| (isop(expr[i]) && !isspace(expr[i - 1])))) {
			std::cerr << "Error" << std::endl;
			return -1;
		}
	}
	return 0;
}

int	main(int ac, char **av) {

	if (ac != 2) {
		std::cerr << "🤡 Arguments must be : ./RPN \"numbers and operations\"" << std::endl;
		return 1;
	}

	std::string expr = av[1];
	if (handle_err(expr) != 0)
		return 1;
	RPN rpn;
	rpn.oper(expr);
	return 0;
}