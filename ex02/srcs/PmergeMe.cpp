/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:46:40 by vagrant           #+#    #+#             */
/*   Updated: 2023/04/17 20:36:45 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "parsing.hpp"

/* ==========================================================================
								COPLIEN FORM 
   ========================================================================== */

PmergeMe::PmergeMe() {
	std::cout << BLUE "PmergeMe default constructor called!\n" RESET;
}

PmergeMe::PmergeMe(PmergeMe const &src) {

	std::cout << BLUE "PmergeMe copy constructor called\n" RESET;
	*this = src;
}

PmergeMe			&PmergeMe::operator=(PmergeMe const &rhs) {

	std::cout << BLUE "PmergeMe assignment operator called!\n" RESET;
	if (this != &rhs)
		return (*this);
	
	return (*this);
}

PmergeMe::~PmergeMe() {
	std::cout << RED "PmergeMe destructor called!\n" RESET;
}

/* ==========================================================================
								MEMBER FUNCTIONS 
   ========================================================================== */

void	sortRecursively(std::vector<int> &bigGuys, size_t size) {

	if (size <= 1)
		return;
	sortRecursively(bigGuys, size - 1);
	for (size_t i = size - 1; i > 0 && bigGuys[i - 1] > bigGuys[i]; --i)
		std::swap(bigGuys[i], bigGuys[i - 1]);
}

std::vector<int> PmergeMe::mergeInsertVec(std::vector<int> &input) {
	
	if (isSorted(input))
		return input;
	
	std::vector<std::pair<int, int>>	myPairs;
	std::vector<int>					bigGuys;

	for (int i = 0; i < input.size(); i += 2)
		myPairs.push_back(std::make_pair(input[i], input[i + 1]));
	for (int i = 0; i < myPairs.size(); i++) {
		if (myPairs[i].second) { // must check second
			if (myPairs[i].first > myPairs[i].second)
				std::swap(myPairs[i].first, myPairs[i].second);
			bigGuys.push_back(myPairs[i].second);
		}
	}
	input.clear();
	sortRecursively(bigGuys, bigGuys.size());
	input = bigGuys;
	int	already;
	for (int i = 0; i < myPairs.size(); i++) { // insert smallest bigGuys value
		if (bigGuys.front() == myPairs[i].second) {
			input.insert(input.begin(), myPairs[i].first);
			already = myPairs[i].first;
		}
	}
	for (int i = 0; i < myPairs.size(); i++)
		if (myPairs[i].first != already)
			input.insert(std::lower_bound(input.begin(), input.end(), myPairs[i].first), myPairs[i].first);
	return input;
}

std::list<int>		PmergeMe::mergeInsertList(std::list<int> &input) {
	
	return (input);
}

