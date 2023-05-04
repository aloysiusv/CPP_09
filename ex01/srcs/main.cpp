/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:15:08 by lrandria          #+#    #+#             */
/*   Updated: 2023/05/04 19:15:23 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av) {

	std::string	expr; 
	
	/* PARSING */
	if (ac != 2)
		return err(E_BAD_USE);
	expr = av[1];
	if (expr == "")
		return err(E_EMPTY);
	if (isop(expr[0]))
		return err(E_BAD_START);
	for (size_t i = 0; i < expr.size(); ++i) {
		if (!isdigit(expr[i]) && !isspace(expr[i]) && !isop(expr[i]))
			return err(E_INVALID_CHAR);
		if (i != 0 && ((isdigit(expr[i]) && !isspace(expr[i - 1]))
			|| (isop(expr[i]) && !isspace(expr[i - 1]))))
			return err(E_NO_SPACE);
	}
	
	/* LET'S GO */
	RPN		rpn;
	
	return (rpn.oper(expr));
}
