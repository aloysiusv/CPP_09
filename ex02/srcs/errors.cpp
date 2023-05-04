/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:06:43 by lrandria          #+#    #+#             */
/*   Updated: 2023/05/04 17:07:08 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int err(ErrorCode code) {
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
