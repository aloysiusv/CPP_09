/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:13:16 by estoffel          #+#    #+#             */
/*   Updated: 2023/03/24 02:57:15 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& cpy): stack(cpy.stack) {}

RPN& RPN::operator=(const RPN& asgn) {

	this->stack = asgn.stack;
	return *this;
}

RPN::~RPN() {}

void RPN::oper(const std::string& expr) {
	std::stack<int> stack;
	std::istringstream iss(expr);

	std::string token;
	while (iss >> token) {

		if (isdigit(token[0])) {
			stack.push(atoi(token.c_str()));
		}
		else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
		{
			if (stack.size() < 2)
			{
				std::cout << "Error: not enough operands" << std::endl;
				return ;
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			if (token == "+") {
				stack.push(a + b);
			}
			else if (token == "-") {
				stack.push(a - b);
			}
			else if (token == "*") {
				stack.push(a * b);
			}
			else if (token == "/") {
				if (b == 0) {
					std::cerr << "Error: Can't divide by 0" << std::endl;
					return ;
				}
				stack.push(a / b);
			}
		}
	}
	std::cout << stack.top() << std::endl;
}