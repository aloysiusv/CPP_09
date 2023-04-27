/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:47:30 by lrandria          #+#    #+#             */
/*   Updated: 2023/04/27 18:59:39 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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

bool isop(int c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}
