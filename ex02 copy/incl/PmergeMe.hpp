/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:46:31 by vagrant           #+#    #+#             */
/*   Updated: 2023/04/24 17:17:23 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <sstream>
# include <algorithm>
# include <utility>
# include <iterator>
# include <ctime>

# include <vector>
# include <list>

# include "errors.h"
# include "colours.h"

template<typename T>
void	printContainer(const T container, std::string name);

class PmergeMe {

	public:
		PmergeMe(const char *nums);
		PmergeMe(const PmergeMe &src);
		PmergeMe	&operator=(const PmergeMe &rhs);
		~PmergeMe();

		doSorting(std::vector<int> dummy);
		printTime();

	private:
		std::vector<int>	mergeInsertVec(std::vector<int> &unsorted);
		std::list<int>		mergeInsertLst(std::list<int> &unsorted);

		std::vector<int>	dummy;
		std::vector<int>	vec;
		std::list<int>		lst;
};

# include "printContainer.tpp"
