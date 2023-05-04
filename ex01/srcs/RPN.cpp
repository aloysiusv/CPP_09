/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:16:01 by lrandria          #+#    #+#             */
/*   Updated: 2023/05/04 19:12:55 by lrandria         ###   ########.fr       */
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

int err(ErrorCode code) {
	switch (code) {
		case (E_BAD_USE):
			std::cerr << YELLOW "Error: " RESET "[usage]: ./rpn <expr>\n";
			break;
		case (E_EMPTY):
			std::cerr << YELLOW "Error: " RESET "am I a joke to you?!\n";
			break;
		case (E_BAD_START):
			std::cerr << YELLOW "Error: " RESET "can't start with an operator.\n";
			break;
		case (E_INVALID_CHAR):
			std::cerr << YELLOW "Error: " RESET "invalid chars detected.\n";
			break;
		case (E_NO_SPACE):
			std::cerr << YELLOW "Error: " RESET "elements not separated with spaces.\n";
			break;
		case (E_INSUFFICIENT_OP):
			std::cerr << YELLOW "Error: " RESET "not enough operators.\n";
			break;
		case (E_DIV_BY_ZERO):
			std::cerr << YELLOW "Error: " RESET "can't divide by zero.\n";
			break;
		case (E_TOO_MANY):
			std::cerr << YELLOW "Error: " RESET "incoherent number of elements.\n";
			break;
		default:
			return EXIT_SUCCESS;
	}
	return static_cast<int>(code);
}

bool isop(int c) {

	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}
