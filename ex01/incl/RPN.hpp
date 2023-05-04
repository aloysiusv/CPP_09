/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:14:48 by lrandria          #+#    #+#             */
/*   Updated: 2023/05/04 22:58:20 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "colours.h"
#include <stdlib.h> // atoi and EXIT macros

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

#include <climits> // INT macros


enum ErrorCode {
    E_BAD_USE = 1,
	E_EMPTY,
    E_BAD_START,
    E_INVALID_CHAR,
    E_NO_SPACE,
	E_INSUFFICIENT_OP,
	E_DIV_BY_ZERO,
	E_TOO_MANY
};

class RPN {

	public:
		RPN();
		RPN(const RPN& rhs);
		RPN& operator=(const RPN& rhs);
		~RPN();

		int oper(const std::string& expr);

	private:
		std::stack<int>	stack;
};

int		err(ErrorCode code);
bool	isop(int c);
