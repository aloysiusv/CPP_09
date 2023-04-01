/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:46:40 by vagrant           #+#    #+#             */
/*   Updated: 2023/04/01 21:01:15 by lrandria         ###   ########.fr       */
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

std::vector<int>	PmergeMe::mergeInsertVec(std::vector<int> &input) {

	if (isSorted(input) == true)
		return input;
	
	// Step 1: Group the elements into pairs and determine the larger element in each pair
	std::vector<std::pair<int, int> > pairs;
	for (std::vector<int>::iterator it = input.begin(); it != input.end(); it += 2) {
		if (it + 1 == input.end()) {
			pairs.push_back(std::make_pair(*it, *it));
			break;
		}
		pairs.push_back(std::make_pair(*it, *(it + 1)));
	}

	// Step 2: Recursively sort the larger elements from each pair
	std::vector<int> larger;
	larger.reserve(pairs.size());
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		larger.push_back(std::max(it->first, it->second));
	}
	mergeInsertVec(larger);

	// Step 3: Insert the smaller elements into the sorted sequence
	std::vector<int> smaller;
	smaller.reserve(pairs.size());
	for (std::vector<std::pair<int, int> >::reverse_iterator it = pairs.rbegin(); it != pairs.rend(); ++it) {
		smaller.push_back(it->first);
	}
	std::reverse(smaller.begin(), smaller.end());
	for (std::vector<int>::iterator it = smaller.begin(); it != smaller.end(); ++it) {
		std::vector<int>::iterator pos = std::lower_bound(larger.begin(), larger.end(), *it);
		larger.insert(pos, *it);
	}

	// Step 4: Add the last unpaired element to the sorted sequence
	if (input.size() % 2 != 0) {
		std::vector<int>::iterator pos = std::lower_bound(larger.begin(), larger.end(), input.back());
		larger.insert(pos, input.back());
	}

	// Step 5: Assign the sorted elements back to the input vector
	input.swap(larger);
	return (input);
}

std::list<int>		PmergeMe::mergeInsertList(std::list<int> &input) {

	{
	bool is_sorted = true;
	std::list<int>::iterator it = input.begin();
	int prev = *it;
	++it;
	for (; it != input.end(); ++it) {
		if (*it < prev) {
			is_sorted = false;
			break;
		}
		prev = *it;
	}
	if (is_sorted)
		return input;
	}
	
	typedef std::list<int>::iterator Iter;
	std::list<std::pair<int, int> > pairs;
	
	// Group the elements into pairs and find the larger element of each pair
	Iter it = input.begin();
	while (it != input.end()) {
		int x = *it++;
		int y = it == input.end() ? x : *it++;
		pairs.push_back(std::make_pair(std::min(x, y), std::max(x, y)));
	}
	
	// Sort the larger elements of each pair recursively
	std::list<int> larger;
	for (std::list<std::pair<int, int> >::iterator p = pairs.begin(); p != pairs.end(); ++p) {
		larger.push_front(p->second);
	}
	mergeInsertList(larger);
	
	// Insert the smaller elements of each pair at the start of the corresponding larger element
	std::list<int>::iterator lit = input.begin();
	for (std::list<std::pair<int, int> >::iterator p = pairs.begin(); p != pairs.end(); ++p) {
		*lit++ = p->first;
		*lit++ = p->second;
	}
	
	// Insert the remaining elements of the original list into the sorted larger list
	std::list<int>::iterator ins = larger.begin();
	std::advance(ins, pairs.size());
	for (; lit != input.end(); ++lit) {
		ins = std::lower_bound(larger.begin(), ins, *lit);
		ins = larger.insert(ins, *lit);
		std::advance(ins, 1);
	}

	input.swap(larger);
	return (input);
}

