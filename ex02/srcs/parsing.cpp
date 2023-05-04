/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:33:01 by lrandria          #+#    #+#             */
/*   Updated: 2023/05/04 17:32:57 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	hasTwin(std::vector<int> dummy) {
	
	std::sort(dummy.begin(), dummy.end());

	for (int i = 0; i < (int)dummy.size(); i++) {
		if (i != 0)
			if (dummy[i] == dummy[i - 1])
				return true;
	}
	return false;
}

bool	isSorted(std::vector<int> dummy) {

	int	size = dummy.size();

	if (size <= 1)
		return true;
	for (int i = 0; i < size; i++) {
		if (i != 0)
			if (dummy[i] <= dummy[i - 1])
				return false;
	}
	return true;
}

bool	notValid(char **av) {

	int			i = 1;

	std::string	arg;
	while (av[i]) {
		arg = av[i];
		if (arg == "")
			return err(E_EMPTY);
		if (arg.find_first_not_of("0123456789") != arg.npos)
			return err(E_NOT_DIGIT);
		if (atol(arg.c_str()) < INT_MIN || (atol(arg.c_str()) > INT_MAX))
			return err(E_BAD_INT);
		i++;
	}
	return false;
}
