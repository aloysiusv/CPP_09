/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:46:37 by vagrant           #+#    #+#             */
/*   Updated: 2023/04/12 17:50:05 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "parsing.hpp"

static int err(ErrorCode code) {
	switch (code) {
		case (E_BAD_USE):
			std::cerr << YELLOW "Error: " RESET "[usage]: ./PmergeMe <number(s)>\n";
			break;
		case (E_BAD_INT):
			std::cerr << YELLOW "Error: " RESET "only positive integers allowed.\n";
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

int main(int ac, char **av) {

	/* PARSING */

	std::vector<int> dummy;

	if (ac < 2)
		return err(E_BAD_USE);
	if (notValid(av) == true)
		return err(E_BAD_INT);
	else {
		for (int i = 1; i < ac; i++)
			dummy.push_back(atoi(av[i]));
		if (isSorted(dummy) == true)
			return err(E_SORTED);
		if (hasTwin(dummy) == true)
			return err(E_TWIN);
	}
	if (dummy.size() % 2 != 0)
		g_isOdd = true;

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
	printContainer(vec, "Vector");
	printContainer(lst, "List");

	p.mergeInsertVec(vec);
	p.mergeInsertList(lst);

	std::cout << "\nAfter sorting:\n\n";
	printContainer(vec, "Vector");
	printContainer(lst, "List");
}
