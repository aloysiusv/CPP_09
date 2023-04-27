/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:14:48 by lrandria          #+#    #+#             */
/*   Updated: 2023/04/27 19:00:07 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <stdlib.h>

#include "colours.h"
#include "errors.h"

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
