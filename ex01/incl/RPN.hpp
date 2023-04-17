/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:13:20 by estoffel          #+#    #+#             */
/*   Updated: 2023/03/24 02:56:35 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*--------- C O L O R S ---------*/

#define GREY "\033[0;30m"
#define RORED "\033[0;31m"
#define RED "\033[0;91m"
#define GREEN "\033[0;32m"
#define YELW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PINK "\033[0;35m"
#define TURQ "\033[0;36m"
#define WHITE "\033[0;97m"
#define BWHITE "\033[1;97m"
#define LWHITE "\033[4;97m"
#define END "\e[0m"

/*------ L I B R A R I E S ------*/

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <stdlib.h>

/*------- T Y P E D E F S -------*/

typedef	unsigned int	uint;

/*-------- C L A S S E S --------*/

class RPN {

	public:
		RPN();
		RPN(const RPN& cpy);
		RPN& operator=(const RPN& asgn);
		~RPN();

		void oper(const std::string& expr);

	private:
		std::stack<int>	stack;
};

