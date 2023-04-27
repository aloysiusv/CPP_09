/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:16:01 by lrandria          #+#    #+#             */
/*   Updated: 2023/04/27 18:57:50 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
	std::cout << BLUE "Default constructor RPN!\n" RESET;
}

RPN::RPN(const RPN& cpy): stack(cpy.stack) {}

RPN& RPN::operator=(const RPN& rhs) {

	this->stack = rhs.stack;
	return *this;
}

RPN::~RPN() {
	std::cout << RED "Destructor RPN!\n" RESET;
}

int RPN::oper(const std::string& expr) {
	
	std::stack<int>		stack;
	std::istringstream	iss(expr);

	std::string 		token;
	while (iss >> token) {

		if (isdigit(token[0]))
			stack.push(atoi(token.c_str()));
		else if (isop(token[0]))
		{
			if (stack.size() < 2)
				return err(E_INSUFFICIENT_OP);
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			if (token == "+")
				stack.push(a + b);
			else if (token == "-")
				stack.push(a - b);
			else if (token == "*")
				stack.push(a * b);
			else if (token == "/") {
				if (b == 0)
					return err(E_DIV_BY_ZERO);
				stack.push(a / b);
			}
		}
	}
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
		return err(E_TOO_MANY);
	return EXIT_SUCCESS;
}
