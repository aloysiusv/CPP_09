/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:52:13 by lrandria          #+#    #+#             */
/*   Updated: 2023/03/23 01:53:49 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
	std::cout << BLUE "Default constructor RPN!\n" RESET;
}

RPN::RPN(const RPN &rhs) : x(rhs.x) {
};

RPN& RPN::operator=(const RPN &rhs) {

	this->x = rhs.x;
	return *this;
}

RPN::~RPN() {
	std::cout << RED "Destructor RPN!\n" RESET;
}
