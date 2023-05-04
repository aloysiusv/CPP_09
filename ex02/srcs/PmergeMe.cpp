/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:46:40 by vagrant           #+#    #+#             */
/*   Updated: 2023/05/04 16:47:07 by lrandria         ###   ########.fr       */
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

static void	sortRecursivelyVec(std::vector<int> &bigGuys, size_t size) {

	if (size <= 1)
		return;
	sortRecursivelyVec(bigGuys, size - 1);
	for (size_t i = size - 1; i > 0 && bigGuys[i - 1] > bigGuys[i]; --i)
		std::swap(bigGuys[i], bigGuys[i - 1]);
}

std::vector<int> PmergeMe::mergeInsertVec(std::vector<int> &input) {
	
	std::vector<std::pair<int, int> >	myPairs;
	std::vector<int>					bigGuys;
	std::vector<int>::iterator 			it = input.begin();

	std::clock_t start = std::clock();

	while (it != input.end()) {
		
		int	first = *it++;
		int	second = 0;
		
		if (it != input.end())
			second = *it++;
		myPairs.push_back(std::make_pair(first, second));
	}
	for (size_t i = 0; i < myPairs.size(); i++) {
		if (myPairs[i].second) { // must check second
			if (myPairs[i].first > myPairs[i].second)
				std::swap(myPairs[i].first, myPairs[i].second);
			bigGuys.push_back(myPairs[i].second);
		}
	}
	input.clear();
	sortRecursivelyVec(bigGuys, bigGuys.size());
	input = bigGuys;
	int	already = 0;
	for (size_t i = 0; i < myPairs.size(); i++) { // insert smallest bigGuys value
		if (bigGuys.front() == myPairs[i].second) {
			input.insert(input.begin(), myPairs[i].first);
			already = myPairs[i].first;
		}
	}
	for (size_t i = 0; i < myPairs.size(); i++)
		if (myPairs[i].first != already)
			input.insert(std::lower_bound(input.begin(), input.end(), myPairs[i].first), myPairs[i].first);
	
	std::clock_t end = std::clock();
	double	time = static_cast<double>(end - start) * 1000000 / CLOCKS_PER_SEC; // calculate time in seconds
	std::cout << "\nTime to process a range of " << input.size() << " elements with std::vector: " 
			  << time << "us.\n";
	return input;
}

static void	sortRecursivelyLst(std::list<int> &bigGuys, size_t size) {

	if (size <= 1)
		return;
	sortRecursivelyLst(bigGuys, size - 1);

	std::list<int>::iterator	it = bigGuys.begin();
	std::advance(it, size - 1);
	std::list<int>::iterator	prevIt = it;
	--prevIt;
	while (it != bigGuys.begin() && *prevIt > *it) {

		std::iter_swap(it, prevIt);
		it = prevIt;
		--prevIt;
	}
}

std::list<int> PmergeMe::mergeInsertLst(std::list<int> &input) {

	std::list<std::pair<int, int> >	myPairs;
	std::list<int>					bigGuys;
	std::list<int>::iterator 		it = input.begin();
	
	std::clock_t start = std::clock();

	while (it != input.end()) {
		
		int	first = *it++;
		int	second = 0;
		
		if (it != input.end())
			second = *it++;
		myPairs.push_back(std::make_pair(first, second));
	}
	for (std::list<std::pair<int, int> >::iterator it = myPairs.begin(); it != myPairs.end(); ++it) {
		if (it->second) {
			if (it->first > it->second)
				std::swap(it->first, it->second);
			bigGuys.push_back(it->second);
		}
	}
	input.clear();
	sortRecursivelyLst(bigGuys, bigGuys.size());
	input = bigGuys;
	int	already = 0;
	for (std::list<std::pair<int, int> >::iterator it = myPairs.begin(); it != myPairs.end(); ++it) {
		if (bigGuys.front() == it->second) {
			input.push_front(it->first);
			already = it->first;
		}
	}
	for (std::list<std::pair<int, int> >::iterator it = myPairs.begin(); it != myPairs.end(); ++it) {
		if (it->first != already) {
			std::list<int>::iterator insertIt = input.begin();
			while (insertIt != input.end() && *insertIt < it->first) {
				++insertIt;
			}
			input.insert(insertIt, it->first);
		}
	}
	
	std::clock_t end = std::clock();
	double	time = static_cast<double>(end - start) * 1000000 / CLOCKS_PER_SEC; // calculate time in seconds
	std::cout << "\nTime to process a range of " << input.size() << " elements with std::list: " 
			  << time << "us.\n";
	
	return input;
}
