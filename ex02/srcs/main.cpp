/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagrant <vagrant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:46:37 by vagrant           #+#    #+#             */
/*   Updated: 2023/03/24 17:47:03 by vagrant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int err(ErrorCode code) {
	switch (code) {
		case (E_BAD_USE):
			std::cerr << YELLOW "Error: " RESET "[usage]: ./PmergeMe <number(s)>\n";
			break;
		case (E_BAD_NUM):
			std::cerr << YELLOW "Error: " RESET "only numbers allowed\n.";
			break;
		case (E_BAD_INT):
			std::cerr << YELLOW "Error: " RESET "only integers allowed.\n";
			break;
		case (E_BAD_SIGN):
			std::cerr << YELLOW "Error: " RESET "only positive integers allowed\n.";
			break;
		case (E_TWIN):
			std::cerr << YELLOW "Error: " RESET "values must be unique\n";
			break;
		default:
			return EXIT_SUCCESS;
	}
	return static_cast<int>(code);
}

int main(int ac, char **av) {

	if (ac < 2)
		return err(E_BAD_USE);

	int	i = 0;
	while (av[i]) {
		int j = 0;
		if (isdigit(av[i][j]) )
	}
}