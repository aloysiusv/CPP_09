/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:46:37 by vagrant           #+#    #+#             */
/*   Updated: 2023/05/04 19:20:29 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

enum ErrorCode {
	E_BAD_USE = 1,
	E_EMPTY,
	E_NOT_DIGIT,
	E_NO_NEG,
	E_BAD_INT,
	E_TWIN,
	E_SORTED
};

static int err(ErrorCode code) {
	switch (code) {
		case (E_BAD_USE):
			std::cerr << YELLOW "Error: " RESET "[usage]: ./PmergeMe <number(s)>\n";
			break;
		case (E_EMPTY):
			std::cerr << YELLOW "Error: " RESET "empty string, really? :(\n";
			break;
		case (E_NOT_DIGIT):
			std::cerr << YELLOW "Error: " RESET "non-digits detected.\n";
			break;
		case (E_NO_NEG):
			std::cerr << YELLOW "Error: " RESET "only positive integers allowed.\n";
			break;
		case (E_BAD_INT):
			std::cerr << YELLOW "Error: " RESET "value(s) exceeded int capacity.\n";
			break;
		case (E_TWIN):
			std::cerr << YELLOW "Error: " RESET "values must be unique\n";
			break;
		case (E_SORTED):
			std::cerr << YELLOW "Warning: " RESET "your sequence is already sorted.\n";
			break;
		default:
			return EXIT_SUCCESS;
	}
	return static_cast<int>(code);
}

static bool	hasTwin(std::vector<int> dummy) {
	
	std::sort(dummy.begin(), dummy.end());

	for (int i = 0; i < (int)dummy.size(); i++) {
		if (i != 0)
			if (dummy[i] == dummy[i - 1])
				return true;
	}
	return false;
}

static bool	isSorted(std::vector<int> dummy) {

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

static bool	notValid(char **av) {

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

int main(int ac, char **av) {

	/* PARSING */
	std::vector<int>	dummy;

	if (ac < 2)
		return err(E_BAD_USE);
	if (notValid(av))
		return EXIT_FAILURE;
	else {
		for (int i = 1; i < ac; i++)
			dummy.push_back(atoi(av[i]));
		if (isSorted(dummy) == true)
			return err(E_SORTED);
		if (hasTwin(dummy) == true)
			return err(E_TWIN);
	}

	/* LET'S GO */
	PmergeMe			p;
	std::vector<int>	vec;
	std::list<int>		lst;
	int					newElem;

	for (int i = 1; i < ac; i++) {
		newElem = atoi(av[i]);
		vec.push_back(newElem);
		lst.push_back(newElem);
	}
	std::cout << "\nBefore sorting:\n\n";
	p.printContainer(vec, "Vector");
	p.printContainer(lst, "List");

	p.mergeInsertVec(vec);
	p.mergeInsertLst(lst);

	std::cout << "\nAfter sorting:\n\n";
	p.printContainer(vec, "Vector");
	p.printContainer(lst, "List");
}
