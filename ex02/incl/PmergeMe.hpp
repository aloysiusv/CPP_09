/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:46:31 by vagrant           #+#    #+#             */
/*   Updated: 2023/05/04 17:14:49 by lrandria         ###   ########.fr       */
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
# include <climits>

# include <vector>
# include <list>

# include "errors.hpp"
# include "parsing.hpp"
# include "colours.h"

template<typename T>
void	printContainer(const T container, std::string name);

class PmergeMe {

	public:
		PmergeMe();
		PmergeMe(const std::vector<int>);
		PmergeMe(const PmergeMe &src);
		PmergeMe	&operator=(const PmergeMe &rhs);
		~PmergeMe();

		std::vector<int>	mergeInsertVec(std::vector<int> &unsorted);
		std::list<int>		mergeInsertLst(std::list<int> &unsorted);
};

# include "printContainer.tpp"
