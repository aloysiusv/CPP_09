/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:46:37 by vagrant           #+#    #+#             */
/*   Updated: 2023/05/04 17:14:07 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
	printContainer(vec, "Vector");
	printContainer(lst, "List");

	p.mergeInsertVec(vec);
	p.mergeInsertLst(lst);

	std::cout << "\nAfter sorting:\n\n";
	printContainer(vec, "Vector");
	printContainer(lst, "List");
}
